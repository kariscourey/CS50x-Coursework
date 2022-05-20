import csv

houses = {
    "gryff": 0,
    "huffle": 0,
    "raven": 0,
    "slyth": 0,
}

with open("hogwarts.csv", "r") as file:
    # reader = csv.reader(file)
    reader = csv.DictReader(file)
    next(reader)
    for row in reader:
        house = row["House"]
        # house = row[1]
        houses[house] += 1

for house in houses:
    count = houses[house]
    print(f"{house}: {count}")