class RangeError(Exception):
    # define error if value out of range
    pass


def main():
    # populate change
    change = get_change()

    # populate coins
    coins = get_coins(change)

    # print
    print(coins)


def get_coins(change):
    # initialize coins
    coins = 0

    # calculate quarters
    quarters = int(change / 0.25)
    change = change % 0.25
    coins += quarters

    # calculate dimes
    dimes = int(change / 0.10)
    change = change % 0.10
    coins += dimes

    # calculate nickels
    nickels = int(change / 0.05)
    change = change % 0.05
    coins += nickels

    # calculate pennies
    pennies = int(change / 0.01)
    change = change % 0.01
    coins += pennies

    return coins


def get_change():
    while True:
        try:
            # get user input
            change = float(input("Change owed: "))

            # evaluate input against acceptable range
            if change < 0:
                raise RangeError

        # check value
        except ValueError:
            print("Not a float!")

        # check if in range
        except RangeError:
            print("Not within range!")

        else:
            return change


main()