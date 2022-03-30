#include "helpers.h"

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
    int quantity;

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

            //for k (height) bet -1 and +1
            for (int k = -1; k <= 1; k++)
            {
            //for l (width) bet -1 and +1
                for (int l = -1; l <= 1; k++)
                {
                    //if height outside of range of image
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }
                    //if width outside of range of image
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }

                    //sum RBG values
                    *red += copy[i + k][j + l].rgbtRed;
                    *blue += copy[i + k][j + l].rgbtBlue;
                    *green += copy[i + k][j + l].rgbtGreen;

                    //record quantity
                    quantity++;
                }
            }


            //set red value of image to average of red
            *red = round(*red/quantity);

            //set blue value of image to average of blue
            *blue = round(*blue/quantity);

            //set blue value of image to average of green
            *green = round(*green/quantity);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
