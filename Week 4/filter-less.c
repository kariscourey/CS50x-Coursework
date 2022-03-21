#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    //for each 24-bit pixel in image height
    for (int i = 0; i < height; i++)
    {

        //for each 24-bit pixel in image width
        for (int j = 0; j < width; j++)
        {
            //obtain red value
            BYTE *red = &image[i][j].rgbtRed;

            //obtain blue value
            BYTE *blue = &image[i][j].rgbtBlue;

            //obtain green value
            BYTE *green = &image[i][j].rgbtGreen;

            //average red, blue, and green values
            float average = (*red + *blue + *green)/3.0;

            //set red value to average
            *red = round(average);

            //set blue value to average
            *blue = round(average);

            //set green value to average
            *green = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //for each 24-bit pixel in image height
    for (int i = 0; i < height; i++)
    {

        //for each 24-bit pixel in image width
        for (int j = 0; j < width; j++)
        {
            //obtain red value
            BYTE *red = &image[i][j].rgbtRed;

            //obtain blue value
            BYTE *blue = &image[i][j].rgbtBlue;

            //obtain green value
            BYTE *green = &image[i][j].rgbtGreen;

            //obtain sepiaRed
            float sepiaRed = 0.393 * *red + 0.769 * *green + 0.189 * *blue;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            //obtain sepiaGreen
            float sepiaGreen = .349 * *red + .686 * *green + .168 * *blue;

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            //obtain sepiaBlue
            float sepiaBlue = .272 * *red + .534 * *green + .131 * *blue;

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //set red value to sepiaRed
            *red = round(sepiaRed);

            //set blue value to sepiaBlue
            *blue = round(sepiaBlue);

            //set green value to sepiaGreen
            *green = round(sepiaGreen);

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    int halfwidth = width/2;

    //for each 24-bit pixel in image height
    for (int i = 0; i < height; i++)
    {
        //for each 24-bit pixel in image width
        for (int j = 0; j < halfwidth; j++)
        {
            //set contents of address of [i][j] to tmp
            //tmp = a
            RGBTRIPLE tmp = image[i][j];

            //set [i][j] contents of address to contents of address of [i][halfwidth-j]
            //a = b
            image[i][j] = image[i][width-j-1];

            //set contents of address of [i][width-j] to tmp
            //b = tmp
            image[i][width-j-1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
