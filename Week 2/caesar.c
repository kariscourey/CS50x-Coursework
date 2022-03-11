#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool only_digits(string input);

int main(int argc, string argv[])
{
    //check if one arg (argc == 1), else output error, return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if(only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//check if arg is int
bool only_digits(string input)
{
    bool only_digits = true;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
    int test = (isdigit(input[i]));
    char test2 = input[i];
    if ((isdigit(input[i])))
    {
        only_digits = false;
    }
    }

    return only_digits;
}

//check if arg is positive

//ci = (pi + k) % 26, k = input

//for each LETTER in input, add k (maintain case)

    //if LETTER + k != bet 65 and 90 (uppercase) or bet 97 and 122 (lowercase)
    //(LETTER + k) - 90 or (LETTER + k) - 122

//output "plaintext:  "

//prompt user for string

//output "ciphertext: CIPHERTEXT"

//output newline

//return 0