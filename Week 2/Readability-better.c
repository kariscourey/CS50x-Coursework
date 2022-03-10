#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//prototypes
int grade_index(int letters, int words, int sentences);
void grade_level(int index);

int main(void)
{
    //prompt user for input
    string input = get_string("What's your text, friend?\n");

    //define variable for grade index
    int i = 0;
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int n = strlen(input);

    while (i < n)
    {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))
        {
            letters++;
        }
        else if (input[i] == 32)
        {
            words++;
        }
        else if (input[i] == 46 || input[i] == 33 || input[i] == 63)
        {
            sentences++;
        }
    }

    //determine grade index
    int index = grade_index(letters, words, sentences);

    //determine grade level
    grade_level(index);
}


//returns grade index
int grade_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    //coleman lieu algorithm
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}


//returns grade level
void grade_level(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
}