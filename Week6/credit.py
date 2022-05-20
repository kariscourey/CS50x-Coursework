from sys import exit


class RangeError(Exception):
    # define error if value out of range
    pass


def main():
    # populate cardnumber
    cardnumber = get_cardnumber()

    if get_luhn(cardnumber):

        # call get_cardtype
        get_cardtype(cardnumber)

        # exit
        exit(0)

    # print invalid
    print("INVALID")

    # exit error
    exit(1)


def get_luhn(cardnumber):

    # type to string
    cardnumber = str(cardnumber)

    # get length
    length = len(cardnumber)

    # initialize sum
    sum = 0

    # initialize everyother digit
    everyother = False

    for i in range(length - 1, -1, -1):
        digit = int(cardnumber[i])

        # multiply if every other digit
        if everyother == True:
            digit = digit * 2

        # add to sum
        sum += digit // 10
        sum += digit % 10

        # set everyother
        everyother = not everyother

    # evaluate mod
    if sum % 10 == 0:
        return True

    else:
        return False


def get_cardtype(cardnumber):

    # get first digit
    firstdigit = int(str(cardnumber)[0])

    # assess cardtype given first digit
    if (firstdigit == 3):
        print("AMEX")

    elif (firstdigit == 5):
        print("MASTERCARD")

    elif (firstdigit == 4):
        print("VISA")

    else:
        print("INVALID")


def get_cardnumber():
    while True:
        try:
            # get user input
            cardnumber = int(input("Card number: "))

            # evaluate input against acceptable range
            if cardnumber <= 0:
                raise RangeError

        # check value
        except ValueError:
            print("Not an int!")

        # check if in range
        except RangeError:
            print("Not within range!")

        else:
            return cardnumber


main()