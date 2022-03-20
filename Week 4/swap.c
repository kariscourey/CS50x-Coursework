#include <stdio.h>

void swap(int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 1;

    printf("x is %i, y is %i\n", x, y);
    // swap(x, y);
    swap(&x, &y); // address of x and y
    printf("x is %i, y is %i\n", x, y);

}

// void swap(int a, int b) //functions call copies of variables

void swap(int *a, int *b) //point to address of a and b
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}