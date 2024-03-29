import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # initialize variables
    user_id = session["user_id"]
    total_total = 0

    # get symbol, shares
    summary = (db.execute("SELECT symbol, SUM(shares) FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) <> 0", user_id))

    # get cash
    cash = (db.execute("SELECT cash FROM users WHERE id = ?", user_id))[0]["cash"]

    # lookup price and calculate total in list
    for i in summary:

        # define shares
        shares = i["SUM(shares)"]

        # define symbol
        symbol = i["symbol"]

        # call lookup on symbol
        price = lookup(symbol)["price"]

        # define total
        total = shares * price

        # add kv pair
        i["price"] = "${:,.2f}".format(price)

        # add kv pair
        i["total"] = "${:,.2f}".format(total)

        # increase total_total
        total_total += total

    # print table
    return render_template("index.html", summary=summary, cash="${:,.2f}".format(cash), grand_total="${:,.2f}".format(total_total + cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # initialize variables
        user_id = session["user_id"]

        # initialize variable
        symbol = request.form.get("symbol").upper().strip()

        # initialize variable
        shares = request.form.get("shares")

        # ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 400)

        try:
            # call lookup on sym
            price = lookup(symbol)["price"]

        except (TypeError):
            # ensure symbol is valid
            return apology("symbol invalid", 400)

        try:
            # typecast variable
            shares = int(shares)

        except (ValueError):
            # ensure shares submitted
            if shares == "":
                return apology("must provide shares", 400)
            # ensure share valid
            else:
                return apology("shares invalid", 400)

        # ensure positive shares
        if shares < 0:
            return apology("shares must be positive", 400)

        # initialize variable
        total = shares * price

        # query db based on logged in user
        cash = (db.execute("SELECT cash FROM users WHERE id = ?", user_id))[0]["cash"]

        # intialize variable
        remainder = cash - total

        # calculate remainder
        if remainder < 0:
            return apology("invalid cash", 403)

        else:

            # update users table
            db.execute("UPDATE users SET cash = ? WHERE id = ?", remainder, user_id)

            # update transactions table
            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, time) VALUES (?, ?, ?, ?, ?)",
                       user_id, symbol, shares, price, datetime.now())

            # render template
            return render_template("bought.html", symbol=symbol, price=price, shares=shares, remainder=remainder, total=total)

    # user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # initialize variables
    user_id = session["user_id"]

    # get transaction info
    summary = (db.execute("SELECT symbol, shares, price, time FROM transactions WHERE user_id = ?", user_id))

    # lookup price and calculate total in list
    for i in summary:

        # define symbol
        symbol = i["symbol"]

        # define shares
        shares = i["shares"]

        # call lookup on symbol
        price = lookup(symbol)["price"]

        # define total
        total = shares * price

        # update kv pair
        i["price"] = "${:,.2f}".format(price)

        # add kv pair
        if total < 0:
            i[" transaction total"] = "${:,.2f}".format(abs(total))
        else:
            i["transaction total"] = "(${:,.2f})".format(total)

    # print table
    return render_template("history.html", summary=summary)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        try:
            # initialize sym
            symbol = request.form.get("symbol").upper().strip()

            # call lookup on sym
            price = lookup(symbol)["price"]

        except:
            return apology("invalid symbol", 400)

        # if (price is None):
        #     # render template ... why isn't this working?
        #     return render_template("quoted.html", symbol=symbol, price="INVALID")

        else:
            # render template, invalid
            return render_template("quoted.html", symbol=symbol, price=price)

    # user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # initialize variables
        un = request.form.get("username")
        pw = request.form.get("password")
        confirm = request.form.get("confirmation")

        # # initialize apol_statement
        # apol_statement = ""

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", un)

        # ensure username was submitted
        if not un:
            # apol_statement += "must provide username! "
            return apology("must provide username", 400)

        # ensure username exists and password is correct
        elif len(rows) != 0:
            return apology("username already registered", 400)

        # # query db for username
        # registered_uns = db.execute("SELECT username FROM users")

        # # ensure username not in db
        # elif un in registered_uns:
        #     # apol_statement += "username already registered! "
        #     print(registered_uns)
        #     return apology("username already registered", 403)

        # ensure password was submitted
        elif not pw:
            # apol_statement += "must provide password! "
            return apology("must provide password", 400)

        # ensure confirm entered
        elif not confirm:
            return apology("must confirm password", 400)

        # # ensure pw formatting
        # elif len(pw) < 10:
        #     return apology("password too short", 400)

        # # ensure pw contains number:
        # elif any(char.isdigit() for char in pw) == False:
        #     return apology("password must contain number", 400)

        # # ensure pw contains special char:
        # elif any((char >= "!" and char <= "/") or (char >= ":" and char <= "@") or (char >= "[" and char <= "`") or (char >= "{" and char <= "~") for char in pw) == False:
        #     return apology("password must contain special character", 400)

        # ensure passwords match
        elif confirm != pw:
            # apol_statement += "passwords don't match! "
            return apology("passwords don't match", 400)

        # # return apology if apol_statement not null
        # if apol_statement == "":
        #     return apology(apol_statement, 403)

        else:
            # hash password
            hashed_pw = generate_password_hash(pw)

            # initialize params
            params = (un, hashed_pw)

            # insert into users
            db.execute("INSERT INTO users(username,hash) VALUES (?)", params)

            # redirect user to home page
            return redirect("/")

    # user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # initialize variables
        user_id = session["user_id"]

        # initialize variable
        symbol = request.form.get("symbol").upper().strip()

        # initialize variable
        shares = request.form.get("shares")

        # ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 400)

        try:
            # call lookup on sym
            price = lookup(symbol)["price"]

        except (TypeError):
            # ensure symbol is valid
            return apology("symbol invalid", 400)

        try:
            # typecast variable
            shares = -1 * int(shares)

        except (ValueError):
            # ensure shares submitted
            if shares == "":
                return apology("must provide shares", 400)
            # ensure share valid
            else:
                return apology("shares invalid", 400)

        # query database for symbol
        shares_inventory = db.execute("SELECT SUM(shares) FROM transactions WHERE user_id = ? AND symbol = ?", user_id, symbol)[
            0]["SUM(shares)"]

        try:
            if shares_inventory <= 0 or shares_inventory + shares < 0:
                return apology("invalid transaction", 400)
        except (TypeError):
            return apology("invalid transaction", 400)

        # ensure positive shares
        if shares > 0:
            return apology("invalid transaction", 400)

        # initialize variable
        total = -1 * shares * price

        # query db based on logged in user
        cash = (db.execute("SELECT cash FROM users WHERE id = ?", user_id))[0]["cash"]

        # intialize variable
        remainder = cash + total

        # update users table
        db.execute("UPDATE users SET cash = ? WHERE id = ?", remainder, user_id)

        # update transactions table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, time) VALUES (?, ?, ?, ?, ?)",
                   user_id, symbol, shares, price, datetime.now())

        # render template
        return render_template("sold.html", symbol=symbol, price=price, shares=shares, remainder=remainder, total=total)

    # user reached route via GET (as by clicking a link or via redirect)
    else:

        # initialize variables
        user_id = session["user_id"]
        symbols = []

        # query database for symbols
        sym_query = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)

        for i in sym_query:
            symbols.append(i["symbol"])

<<<<<<< HEAD
        return render_template("sell.html", symbols=symbols)
=======
        return render_template("sell.html", symbols=symbols)
>>>>>>> 88ba7a74e0eae2df49b57fe4f9a14c3dbb9f50f6
