# from cs50 import get_int
# import cs50

# x = cs50.get_int("x: ")
# y = cs50.get_int("y: ")

# try:
#     x = int(input("x: "))
# except:
#     print("Not an int!")
#     exit()

# try:
#     y = int(input("y: "))
# except:
#     print("Not an int!")
#     exit()

# print(x + y)

from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

z = x / y
print(f"{z:.50f}")