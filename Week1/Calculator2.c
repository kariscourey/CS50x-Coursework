#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    int first_number = get_int("x: ");

    //prompt user for y
    int second_number = get_int("y: ");

    //perform division
    float third_number = (float) first_number/(float) second_number;
    printf("%.50f\n", third_number); //can't due precise number ... will overflow if trying to do more bits than are available
}

//computer with finite number can't express all numbers in the world
//floating point imprecision - inability of computers to represent all real numbers 100% precisely
//int/int = int in C; everything after decimal thrown away by truncation
//e.g. 4/3 = 1.000000
//can use type conversion (e.g. (float)) to convert type
//integer overflow 