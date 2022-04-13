from cs50 import get_string

s = get_string("Agree?").lower()

# if s == "Y" or s == "y":
#     print("Agreed")
# if s == "N" or s == "n":
#     print("Not agreed")

# if s in ["Y", "y", "yes"]:
#     print("Agreed")
# if s in ["N", "n","no"]:
#     print("Not agreed")

if s in ["y", "yes"]:
    print("Agreed")
if s in ["n","no"]:
    print("Not agreed")