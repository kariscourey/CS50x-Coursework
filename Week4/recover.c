#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if one arg
    if (argc != 2)
    {
        printf("Usage: ./recover key\n");
        return 1;
    }

    //set pointer to file
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        //return error if null
        printf("Error: ./recover pointer\n");
        return 1;
    }

    int qty = 0;
    FILE *output = NULL;
    char *filename = malloc(8 * sizeof(char));
    BYTE buffer[512];

    while (fread(buffer, 1, 512, input) == 512)
    {
        //look for 0xff, 0xd8, 0xff, 0xe_ (indicates start of jpeg)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if not first jpeg
            if (qty != 0)
            {
                //close file
                fclose(output);
            }

            //print file name to string, filename
            sprintf(filename, "%03i.jpg", qty);

            //open filename
            output = fopen(filename, "w");

            //increment qty
            qty++;
        }

        //if already found jpeg
        if (output != NULL)
        {
            //write remaining bytes to file
            fwrite(buffer, 1, 512, output);
        }
    }

    //free memory
    free(filename);

    //close jpeg file
    fclose(output);

    //close arg file
    fclose(input);

    return 0;
}
