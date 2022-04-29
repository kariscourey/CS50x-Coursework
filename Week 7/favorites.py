import csv
import re

# # with open("favorites.csv", "r") as file:
# #     reader = csv.reader(file)
# #     next(reader)
# #     for row in reader:
# #         print(row[1])

# #     reader = csv.DictReader(file)
# #     for row in reader:
# #         print(row["title"])

# # titles = []
# # titles = set()
# titles = {}

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper()
#         if title in titles:
#             titles[title] += 1
#         else:
#             titles[title] = 1

#         # if not row["title"] in titles:
#         #     titles.append(row["title"])

#         # if not title in titles:
#         #     titles.append(title)

#         titles.add(title)

# # def get_value(title):
# #     return titles[title]

# for title in sorted(titles, key = lambda title: titles[title], reverse = True): # key = get_value, reverse = True):
#     # print(title)
#     print(title, titles[title])

# counter = 0

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper()
#         # if title == "THE OFFICE":
#         # if "OFFICE" in title:
#         if re.search("^(OFFICE|THE.OFFICE)$", title):
#             counter += 1

# print(f"People who like office: {counter}")

title = input("Title: ").strip().upper()

counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1

print(counter)

# db = cs50.SQL("sqlite:///favorites.db")

# title = input("title: ").strip

# rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title)

# row = rows[0]

# print(row["counter"])