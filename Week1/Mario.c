#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    // while (true)
    // {
    //     n = get_int("Size: ");
    //     if (n<0)
    //     ...
    // }


    do
    {
        // n = get_int("Width: ");
        n = get_int("Size: ");
    }
    while (n<1);

//For each row
    for (int i = 0; i < n; i++)
    {
        // printf("?");
        // printf("#");

        //For each column
        for (int j = 0; j < n; j++)
        {
            //Print a brick
            printf("#");
        }
    }
    //Move to next row
    printf("\n");
}