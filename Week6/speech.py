import pyttsx3

engine = pyttsx3.init()
# engine.say("hello, world")
name = input("What's your name? ")
engine.say(f"hello, {name}")

engine.runAndWait()
