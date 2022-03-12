#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Karl","Karis","Pie","Po","JB"}

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Biggles") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}