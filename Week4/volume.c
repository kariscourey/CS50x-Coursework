// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];
    int16_t buffer;

    //Copy header from input file to outtut file
    //read header_size bytes into header variable from input
    fread(header, 1, HEADER_SIZE, input);
    //write header variable into output
    fwrite(header, 1, HEADER_SIZE, output);


    //Read samples from input file and write updated data to output file
    while (fread(&buffer, 1, sizeof(buffer), input))
    {
        buffer *= factor;
        fwrite(&buffer, 1, sizeof(buffer), output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
