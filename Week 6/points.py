from cs50 import get_int

points = get_int("How many?")

if points < 2:
    print("You lost fewer")
elif points > 2:
    print("You lost more")
else:
    print("Lost same")