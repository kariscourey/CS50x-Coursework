from sys import exit


class RangeError(Exception):
    # define error if value out of range
    pass


def main():
    # populate height
    height = get_height()

    # print # for each item in height
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)


def get_height():
    while True:
        try:
            # get user input
            height = int(input("Height?: "))

            # evaluate input against acceptable range
            if height <= 0 or height >= 9:
                raise RangeError

        # check if not an int
        except ValueError:
            print("Not an int!")

        # check if in range
        except RangeError:
            print("Not within range!")

        else:
            return height


main()