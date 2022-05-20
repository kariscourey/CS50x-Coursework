# import sys, use sys.exit instead
from sys import argv, exit

if len(argv) != 2:
    print("Missing command-line arg")
    exit(1)

print(f"Hello, {argv[1]}")
exit(0)