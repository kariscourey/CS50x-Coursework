#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    // char *s; //doesn't work because need to make space for it
    // char *s = malloc(4);
    // char s[4]; //array of 4 chars
    printf("s: ");
    scanf("%s", s); //not necessary to do &s
    printf("s: %s\n", s);

    // free(s);
}