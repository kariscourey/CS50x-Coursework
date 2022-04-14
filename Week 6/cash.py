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

    for i in [0.25, 0.10, 0.05, 0.01]:
        # calculate coins
        if change >= i:
            remainder = round(change % i, 2)
            coins += round((change - remainder) / i)
            change = remainder

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