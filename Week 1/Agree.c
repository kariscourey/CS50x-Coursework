#include <cs50.h>
#include <stio.h>

int main(void)
{
    //prompt user to agree
    char c = get_char("Do you agree? "); //single characters MUST use single quotes

    //check whether user agreed
    if (c == 'y' || c == 'Y') //|| is or, && is and
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N') //have to ask complete question (not c == 'y' or 'Y')
    {
        printf("Not agreed.\n");
    }
}