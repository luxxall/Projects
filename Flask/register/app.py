from flask import Flask, redirect, render_template, request

app = Flask(__name__)

REGISTRANTS = {}
SPORTS = ['Basketball', 'Football', 'Frisbee']

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    #validate name
    name = request.form.get("name")
    if not name:
        return render_template("failure.html", message="Missing name.")
    
    #validate sport
    sport = request.form.get("sport")
    if not sport or sport not in SPORTS:
        return render_template("failure.html", message="Missing sport.")
    
    #remember users
    REGISTRANTS[name] = sport
    
    #confirm
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
    