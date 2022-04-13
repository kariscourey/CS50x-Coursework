from sys import exit

def main():
    # populate height
    height = get_height()

    #print # for each item in height
    for i in range(1,height + 1):
        print(" " * (height - i) + "#" * i)

def get_height():
    while True:
        try:
            # get user input
            height = int(input("Height?: "))

        # check if not an int
        except ValueError:
            print("Not an int!")

        except height < 0 or height > 9:
            print("Not within range!")

        else:
            return height

main()