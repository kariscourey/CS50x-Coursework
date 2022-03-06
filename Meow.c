#include <cs50.h> //these also have protoypes - tell computer what to expect
#include <stio.h>

//function must be identified before it's called
//leave breadcrumb of function (prototype) for compiler at top
//include semicolon - "i'm not going to deal with this yet"
void meow(int n);

int main(void) //main is main part of program, should be at top of code
{
    meow(3); //modularize code
}

void meow(int n) //first void = no return variables, second void = no inputs 
{
    for(int i = 0; i<n; i++)
    {
    printf("meow\n");
    }
}


//alternatively
int main(void)
{
int i = 0; // i = 1; also possible
while(i < 3) // (i <= 3)
{
    printf("meow\n");
    i++;
}
}

alternatively
int main(void)
{
for (int i = 0; i < 3; i++) //initialize, condition before do, execute what's in the loop
{ //variable declared inside loop, so cannot be called elsewhere .. disadvantage
    printf("meow\n");
}
}