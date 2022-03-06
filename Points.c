#include <cs50.h>
#include <stio.h>

int main(void)
{
    int points = get_int("How many points did you lose? ");

    if (points < 2)
    {
        printf("You lost fewer than me.\n");
    }
    else if (points > 2)
    { 
        printf("You lost more points than me.\n");
    }
    else{
        printf("You lost the same number of points as me.\n")
    }

}