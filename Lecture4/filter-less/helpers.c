#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_rgb = round((image[i][j].rbgtRed + image[i][j].rbgtGreen + image[i][j].rbgtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = 0.393 * image[i][j].rbgtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            sepiaGreen = 0.349 * image[i][j].rbgtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            sepiaBlue = 0.272 * image[i][j].rbgtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a replica of the image
    RGBTRIPLE image_replica[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_replica[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j ++)
        {
            int totalred, totalgreen, totalblue;
            totalred = totalgreen = totalblue = 0;
            float counter = 0.00;

            // get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    //Check if neighbouring pixel is valid
                    if (currentx < 0 || currentx > (height - 1) || currenty < 0 || currenty > (width - 1))
                    {
                        continue;
                    }

                    //get image value
                    totalred += image[currentx][currenty].rgbtRed;
                    totalgreen += image[currentx][currenty].rgbtGreen;
                    totalblue += image[currentx][currenty].rgbtBlue;

                    counter++;
                }
                // Calculate average of neighbouring pixels
                image_replica[i][j].rgbtRed = round(totalred / counter);
                image_replica[i][j].rgbtGreen = round(totalgreen / counter);
                image_replica[i][j].rgbtBlue = round(totalblue / counter);

            }
        }
    }
    // Copy new pixels into the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image_replica[i][j].rgbtRed;
            image[i][j].rgbtGreen = image_replica[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image_replica[i][j].rgbtBlue;
        }
    }
    return;
}
