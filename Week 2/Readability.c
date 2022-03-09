#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("What's your text, friend?\n");
    printf("Text: %s\n", text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = grade_index(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (grade >= 1 and grade < 16)
    {
        printf("Grade %i", grade);
    }

}

int count_letters(string text)
{
    int i = 0;
    int n = strlen(text);

    while (i < n)
    {
        if (text[i] != 32)
        {
            i++;
        }
        else
        {
            continue;
        }
    }
    return i;
}

int count_words(string text)
{
    int i = 0;
    int n = strlen(text);

    while (i < n)
    {
        if (text[i]) == 32)
        {
            i++;
        }
        else
        {
            continue;
        }
    }
    return i;
}

int count_sentences(string text)
{
    int i = 0;
    int n = strlen(text);

    while (i < n)
    {
        if (text[i] == 46 or text[i] == 44 or text[i] == 63)
        {
            i++;
        }
        else
        {
            continue;
        }
    }
    return i;
}

int grade_index(int letters, int words, int sentences)
{
    float L = letters / words * 100.0;
    float S = sentences / words * 100.0;
    
    int index = round(0.0588*L - 0.296*S - 15.8);

    return index;
}