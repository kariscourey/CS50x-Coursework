#include <cs50.h>
#include <string.h>

int main(void)
{
    // string s = "HI!";
    // char c = s[0];
    // char *p = &c;
    // printf("%p\n", s);

    // char *p = &s[0];
    // printf("%p\n", p);
    // printf("%p\n", s); //same as above

    // printf("%c\n", s[0]);
    // printf("%c\n", s[1]);
    // printf("%c\n", s[2]);
    // printf("%c\n", s[3]);

    // char *s = "HI!";
    // printf("%c\n", *s);
    // printf("%c\n", *(s+1));
    // printf("%c\n", *(s+2));

    int numbers[] = {4, 6, 7, 2, 7, 5, 0};

    printf("%i\n", numbers); //can treat array as pointer
    printf("%i\n", *(numbers+1));
    printf("%i\n", *(numbers+2));
    printf("%i\n", *(numbers+3));
    printf("%i\n", *(numbers+4));
    printf("%i\n", *(numbers+5));
    printf("%i\n", *(numbers+6));

}