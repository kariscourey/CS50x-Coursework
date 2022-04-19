from sys import exit


def main():
    # populate cardnumber
    text = get_text()

    # populate grade
    grade = get_grade(text)

    # print grade
    print_grade(grade)

    # exit
    exit(0)


def print_grade(grade):

    # print grade
    if grade < 1:
        print("Before Grade 1")

    elif grade >= 16:
        print("Grade 16+")

    else:
        print("Grade " + str(grade))


def get_grade(text):

    # initialize values
    sentences = 0
    letters = 0
    words = 1

    for i in range(0, len(text)):

        # get letters
        if (text[i].isalpha()):
            letters += 1

        # get sentences
        elif text[i] in ["?", "!", "."]:
            sentences += 1

        # get words
        elif text[i] == " ":
            words += 1

        # ignore
        else:
            pass

    # calc grade
    grade = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)

    # return
    return grade


def get_text():

    # get user input
    text = input("Text: ")

    # return
    return text


main()