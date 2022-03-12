#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string names[] = {"Carter", "David"}
    string numbers[] = {"1-888-888-8888", "1-000-000-0000"}

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}