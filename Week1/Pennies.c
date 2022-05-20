#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    int pennies = round(amount * 100);
    printf("Pennies: %i\n", pennies)
}

//at 4.20 without round, returns 419 because storing issue