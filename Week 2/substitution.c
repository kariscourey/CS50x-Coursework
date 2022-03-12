#include <cs50.h>
#include <stdio.h>
#include <string.h> //for strlen
#include <ctype.h> //for isupper, islower

//prototypes
bool only_letters(string input);
int sub_index(char input);

int main(int argc, string argv[])
{
    //check if one arg (argc == 1) and if int
    if ((argc != 2) || (only_letters(argv[1]) == false))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //check if 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //check for duplicate letters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                return 1;
            }
        }
    }

    //prompt for plaintext
    string plaintext = get_string("plaintext: ");

    //print ciphertext label
    printf("ciphertext: ");

    //sub per cipher
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int index = sub_index(plaintext[i]);
        char output = argv[1][index];

        //adjust output case if key case doesn't match plaintext
        if (isupper(plaintext[i]) && islower(output))
        {
            output = output - 32;
        }
        else if (islower(plaintext[i]) && isupper(output))
        {
            output = output + 32;
        }

        //assign plaintext as output if not letter
        else if (!(isalpha(plaintext[i])))
        {
            output = plaintext[i];
        }

        printf("%c", output);
    }

    //print newline
    printf("\n");
    return 0;

}

//check if arg is letters
bool only_letters(string input)
{
    bool only_alpha = true;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!(isalpha(input[i])))
        {
            only_alpha = false;
        }
    }
    return only_alpha;
}

//sub cipher index
int sub_index(char input)
{

    //initialize variables
    int low;
    int high;
    int index;
    int output;

    //check case
    if (isupper(input))
    {
        low = 65;
        high = 90;
    }
    if (islower(input))
    {
        low = 97;
        high = 122;
    }

    //return cipher letter index
    index = input - low;

    return index;
}