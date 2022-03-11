#include <cs50.h>
#include <stdio.h>
#include <string.h> //for strlen
#include <ctype.h> //for isupper, islower
#include <stdlib.h> //for atoi

//prototypes
bool only_digits(string input);
char rotate(char input, int k);

int main(int argc, string argv[])
{
    //check if one arg (argc == 1) and if int
    if ((argc != 2) || (only_digits(argv[1]) == false))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //convert to int
    int k = atoi(argv[1]);

    //prompt for plaintext
    string input = get_string("plaintext: ");

    //print ciphertext label
    printf("ciphertext: ");

    //rotate per caesar cipher
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        //print ciphertext
        char output = rotate(input[i], k);
        printf("%c", output);
    }

    //print newline
    printf("\n");

}

//check if arg is int
bool only_digits(string input)
{
    bool only_digits = true;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!(isdigit(input[i])))
        {
            only_digits = false;
        }
    }
    return only_digits;
}

//caesar cipher (ci = (pi + k) % 26)
char rotate(char input, int k)
{

    //initialize variables
    int output;
    int low;
    int high;
    bool letter = false;

    //check case
    if (isupper(input))
    {
        low = 65;
        high = 90;
        letter = true;
    }
    if (islower(input))
    {
        low = 97;
        high = 122;
        letter = true;
    }

    //if letter (cipher letter)
    if (letter)
    {
        input = input - low;
        output = ((input + k) % 26) + low;
    }

    //if non-letter (print non-letter)
    else
    {
        output = input;
    }

    return output;
}