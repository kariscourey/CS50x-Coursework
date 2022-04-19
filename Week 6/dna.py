import csv
from sys import argv, exit


def main():

    # Check for command-line usage
    if get_usage(argv) == False:
        print("Error python dna.py usage")
        exit(1)

    # Read database file into a variable
    with open(argv[1], "r") as file:

        # read db into variable
        db_reader = csv.reader(file)

        # read headers
        next(db_reader)

        # initialize subsequences
        subsequences = []

        # populate subsequences
        for row in db_reader:
            subsequences.append(row)

    # Read DNA sequence file into a variable
    with open(argv[2], "r") as file:
        seq_reader = csv.reader(file)

    # Find longest match of each STR in DNA sequence
    longest_match = longest_match(seq_reader)

    # Check database for matching profiles

    exit(0)

def get_usage(arg):
    if len(arg) == 3:
        return True
    return False

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
