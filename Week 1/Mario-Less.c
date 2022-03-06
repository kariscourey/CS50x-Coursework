#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initialize height variable
    int height;

    do
    {
        //prompt for pyramid height, populate height variable
        height = get_int("How high is the pyramid? ");
    }
    while (height < 1 || height > 8);

//for each column
    for (int i = 0; i < height; i++)
    {
        //for each row, add spaces = height - i - 1
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        //for each row, add # = i-k
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        //print new line for new column
        printf("\n");
    }

}