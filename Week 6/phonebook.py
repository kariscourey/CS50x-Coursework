# from cs50 import get_string

# people = {
#     "Kate": "1-888-909-1234",
#     "Anthony": "1-888-909-1235"
# }

import csv
from cs50 import get_string

# file = open("phonebook.csv","a")

name = get_string("Name: ")
number = get_string("number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])

# write = csv.writer(file)
# writer.writerow([name, number])

# file.close()


# if name in people:
#     number = people[name]
#     print(f"number: {number}")
#     # print(f"number: {people[name]}")