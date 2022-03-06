#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage);

int main(void)
{
    float regular = get_float("Regular Price: ");
    int percent_off = get_int("Perfect off: ");
    float sale = discount(regular, percent_off); //abstraction, stores return value in a variable, sale
    // float sale = regular * .85;
    printf("Sale price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * (100-percentage)/100 //faster 
    // price = price * (100 - percentage) / 100 //wouldn't hand back discounted price due to scoping
    // float sale = price * .85; 
    // return sale;
}