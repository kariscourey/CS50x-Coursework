#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_index(int letters, int words, int sentences);
void grade_level(int index);

int main(void)
{
    //prompt user for input
    string input = get_string("What's your text, friend?\n");

    //define variable for grade index
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);

    //determine grade index
    int index = grade_index(letters, words, sentences);

    //determine grade level
    grade_level(index);
}

//returns count of letters
int count_letters(string text)
{
    int i = 0;
    int n = strlen(text);
    int letters = 0;

    while (i < n)
    {
        //check if i is a letter
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        i++;
    }
    return letters;
}

//returns count of words based on spaces
int count_words(string text)
{
    int i = 0;
    int n = strlen(text);
    int words = 1;

    while (i < n)
    {
        //check if a space
        if (text[i] == 32)
        {
            words++;
        }
        i++;
    }
    return words;
}

//returns number of sentences based on punctuation
int count_sentences(string text)
{
    int i = 0;
    int n = strlen(text);
    int sentences = 0;

    while (i < n)
    {
        //if puncutation (!, ., ?)
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
        i++;
    }
    return sentences;
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


//returns grade
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