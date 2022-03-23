#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    errno = 0;

    //check if one arg
    if (argc != 2)
    {
        printf("Usage: ./recover key\n");
        return 1;
    }

    //set pointer to file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        //return error if null
        printf("Error: ./recover %d\n", errno);
        return 1;
    }


    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
    }
}
