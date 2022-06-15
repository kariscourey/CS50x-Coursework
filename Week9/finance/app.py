import os

from cs50 import SQL
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
    # TODO
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # initialize variable
        symbol = request.form.get("symbol")

        # call lookup on sym
        price = lookup(symbol)["price"]

        # initialize variable
        shares = request.form.get("shares")

        # ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)

        # ensure symbol is valid
        elif not quote:
            return apology("symbol invalid", 403)

        try:
            # typecast variable
            shares = int(shares)

        except (ValueError):
            # ensure shares submitted
            if shares == "":
                return apology("must provide shares", 403)
            # ensure share valid
            else:
                return apology("shares quantity invalid", 403)

        # initialize variable
        total = shares * price

        # query db
        cash = db.execute("SELECT cash FROM users WHERE username = ?", request.form.get("username"))

        # intialize variable
        remainder = cash - total

        # calculate remainder
        if remainder < 0:
            return apology("invalid cash", 403)

        else:
            # add table with purchase

            # update db with remainder
            # db.execute("SELECT cash FROM users WHERE username = ?", request.form.get("username"))

            # render template
            return render_template("bought.html", symbol=symbol, price=price, shares=shares, total=total)

    # user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # TODO
    return apology("TODO")


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

        # initialize sym
        symbol = request.form.get("symbol")

        # call lookup on sym
        price = lookup(symbol)["price"]

        if (quote is None):
            # render template ... why isn't this working?
            return render_template("quoted.html", symbol=symbol, price="INVALID")

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
            return apology("must provide username", 403)

        # ensure username exists and password is correct
        elif len(rows) != 0:
            return apology("username already registered", 403)


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
            return apology("must provide password", 403)

        # ensure confirm entered
        elif not confirm:
            return apology("must confirm password", 403)

        # ensure passwords match
        elif confirm != pw:
            # apol_statement += "passwords don't match! "
            return apology("passwords don't match", 403)

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
    # TODO
    return apology("TODO")
