# include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_legth(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++
    }
return i;
}