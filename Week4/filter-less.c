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
            float average = (*red + *blue + *green) / 3.0;

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

    int halfwidth = width / 2;

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
            image[i][j] = image[i][width - j - 1];

            //set contents of address of [i][width-j] to tmp
            //b = tmp
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy image[height][width]
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //declare averageColor
    float averageRed;
    float averageBlue;
    float averageGreen;

    //for each 24-bit pixel in image height
    for (int i = 0; i < height; i++)
    {
        //for each 24-bit pixel in image width
        for (int j = 0; j < width; j++)
        {
            //obtain red value of current pixel of image
            BYTE *red = &image[i][j].rgbtRed;

            //obtain blue value of current pixel of image
            BYTE *blue = &image[i][j].rgbtBlue;

            //obtain green value of current pixel of image
            BYTE *green = &image[i][j].rgbtGreen;

            //if on top left corner of copy
            if (i == 0 && j == 0)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed) / 4.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 4.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen) / 4.0;
            }

            //if on bottom left corner of copy
            else if (i == height - 1 && j == 0)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed) / 4.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 4.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen) / 4.0;
            }

            //if on top right corner of copy
            else if (i == 0 && j == width - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed) / 4.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue) / 4.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen) / 4.0;
            }

            //if on bottom right corner of copy
            else if (i == height - 1 && j == width - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed) /  4.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue) / 4.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen) / 4.0;
            }

            //if on edge top edge of copy
            else if (i == 0 && j != 0 && j != width - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1]
                              [j - 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1]
                               [j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1]
                                [j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0;
            }

            //if on left ege of copy
            else if (j == 0 && i != 0 && i != height - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1]
                              [j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1]
                               [j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1]
                                [j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0;
            }

            //if on bottom edge of copy
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1]
                              [j - 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1]
                               [j - 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6.0;
            }

            //if on right edge of copy
            else if (j == width - 1 && i != 0 && i != height - 1)
            {
                averageRed = (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1]
                              [j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1]
                               [j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6.0;
            }

            //if in middle of copy
            else
            {
                averageRed = (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1]
                              [j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed)
                             / 9.0;
                averageBlue = (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1]
                               [j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1]
                               [j + 1].rgbtBlue) / 9.0;
                averageGreen = (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1]
                                [j + 1].rgbtGreen) / 9.0;
            }

            //set red value of image to averageRed
            *red = round(averageRed);

            //set blue value of image to averageBlue
            *blue = round(averageBlue);

            //set blue value of image to averageGreen
            *green = round(averageGreen);
        }
    }

    return;
}