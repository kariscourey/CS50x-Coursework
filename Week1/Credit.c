#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_luhn(long long number);
void get_type(long long number);


int main(void)
{
    long long cardnumber;

    do
    {
    //prompt for card number
    cardnumber = get_long_long("What's your card number? ");
    }

    //prompt loop if card number is less than 0
    while (cardnumber < 0);


    //check luhn if card type passes
    if (get_luhn(cardnumber))
    {
        //if passes, print card type
        get_type(cardnumber);
    }
    else
    {
        //if fails, print invalid
        printf("INVALID\n");
    }
}


int get_luhn(long long number)
{
    int number10 = number/10;
    int num;

while (number10 > 0)
{
    num = number10 % 10 * 2;
    number10 /= 100;

    if(num > 9)
    {
        int num_digit2 = num % 10;
        int num_digit1 = (num - num_digit2)/10;
        num = num_digit1 + num_digit2;
    }

}
return num % 10 == 0;
}

void get_type(long long number)
{

//determine type based on number value and length
    if (number >= 3.4e14 && number < 3.8e14)
    {
        printf("AMEX\n");
    }
    else if (number >= 4.0e12 && number < 5.0e15)
    {
        printf("VISA\n");
    }
    else if (number >= 5.1e15 && number < 5.6e15)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}