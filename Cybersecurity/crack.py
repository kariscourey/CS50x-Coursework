from string import digits, ascii_letters, punctuation
from itertools import product

# for passcode in product(digits, repeat=4):
#     print(*passcode)

# for passcode in product(ascii_letters, repeat=4):
#     print(*passcode)

for passcode in product(ascii_letters + digits + punctuation, repeat=8):
    print(*passcode)