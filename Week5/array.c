#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int list[3];

    //dynamically allocate array of size 3 int
    int *list = malloc(3 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    //assign numbers to array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //time passes

    //resize old array //allocate temp array
    int *tmp = realloc(list, 4 * sizeof(int)); //malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // //copy numbers from old array into new array
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i];
    // }

    //add fourth number to new array
    tmp[3] = 4;

    // //free old array
    // free(list);
    //remember new array
    list = tmp;

    //print new array
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n",list[i]);
    }

    //free new array
    free(list);
    return 0;
}