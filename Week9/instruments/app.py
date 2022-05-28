from flask import Flask, render_template, request

app = Flask(__name__)

INSTRUMENTS = [
    "Trumpet",
    "Ukulele",
    "Piano"
]

@app.route("/")
def index():
    return render_template("index.html", instruments=INSTRUMENTS)

@app.route("/greet", methods=["POST"])
def greet():
    # validate submit
    if not request.form.get("name") or request.form.get("select_instrument") not in INSTRUMENTS: # ["Trumpet","Ukulele","Piano"]:
        return render_template("failure.html")

    #confirm submit
    return render_template("success.html")