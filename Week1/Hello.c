#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompts user for name
    string name = get_string("What say you is your nameth? ");

    //prints name
    printf("Hello, dear, %s.\n", name);
}