#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    long first_number = get_long("x: ");

    //prompt user for y
    long second_number = get_long("y: ");

    //perform addition
    long third_number = first_number+second_number;
    printf("%li", third_number);
}