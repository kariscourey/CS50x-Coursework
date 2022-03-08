#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("What's your text, friend?\n");
    printf("Text: %s\n", text);

    int length = count_letters(text);
    printf("%i letters\n",length);

}

int count_letters(string text)
{
    int i = 0;
    int n = strlen(text);

    while (i < n)
    {
        if ((text[i]) != 20)
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