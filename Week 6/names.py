import sys

names = ["Kay","Kiki","Kate"]

if "Kate" in names:
    print("found")
    sys.exit(0)

print("not found")
sys.exit(1)