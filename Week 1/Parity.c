#include <cs50.h>
#include <stio.h>

int main(void)
{
    int n = get_int("n: ");

    //if n is even
    if (n%2==0)
    {
        printf("even\n");
    }
    //else
    else
    {
        printf("odd\n");
    }
}