#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    int first_number = get_long("x: ");

    //prompt user for y
    int second_number = get_long("y: ");

    //perform addition
    int third_number = x+y;
    printf("%li", third_number);
}