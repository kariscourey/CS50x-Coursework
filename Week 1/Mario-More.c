#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        //prompt for input
        n = get_int("How high? ");
    }
    while (n < 1 || n > 8);

    //for each row, print new line at end
    for(int i = 0; i < n; i++)
    {
        //for each column, print spaces before
        for(int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        //for each column, print # before
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }

        //for each column, print 2 spaces in between
            printf("  ");

        //for each column, print # after
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }

    printf("\n");
    }
}