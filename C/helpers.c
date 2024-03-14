#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    const float subpix = 3.0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg;
            avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / subpix;

            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //loop with sepia algorithm, every rgb is multiplied by specific number
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = (image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen * .769) + (image[i][j].rgbtBlue * .189);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            float sepiaGreen = (image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen * .686) + (image[i][j].rgbtBlue * .168);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            float sepiaBlue = (image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen * .534) + (image[i][j].rgbtBlue * .131);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //set miltiplied values to image
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
    //temp
    RGBTRIPLE buffer;

    for (int i = 0; i < height; i++)
    {
        //loop to swap pixels
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = buffer;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //image copy and varaibles
    RGBTRIPLE copy[height][width];
    float avgRed = 0;
    float avgGreen = 0;
    float avgBlue = 0;
    const float corner = 4.0;
    const float border = 6.0;
    const float middle = 9.0;

    //copy original to temp
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w].rgbtRed = image[h][w].rgbtRed;
            copy[h][w].rgbtGreen = image[h][w].rgbtGreen;
            copy[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //blur the corners
            //left top
            if (i == 0 && j == 0)
            {
                avgRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / corner;
                avgGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / corner;
                avgBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / corner;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //right top
            else if (i == 0 && j == (width - 1))
            {
                avgRed = (copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed +
                          copy[i + 1][j].rgbtRed) / corner;
                avgGreen = (copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                            copy[i + 1][j].rgbtGreen) / corner;
                avgBlue = (copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                           copy[i + 1][j].rgbtBlue) / corner;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //bottom left
            else if (i == (height - 1) && j == 0)
            {
                avgRed = (copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed +
                          copy[i][j + 1].rgbtRed) / corner;
                avgGreen = (copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen +
                            copy[i][j + 1].rgbtGreen) / corner;
                avgBlue = (copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue +
                           copy[i][j + 1].rgbtBlue) / corner;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //bottom right
            else if (i == (height - 1) && j == (width - 1))
            {
                avgRed = (copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed +
                          copy[i][j].rgbtRed) / corner;
                avgGreen = (copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen +
                            copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen) / corner;
                avgBlue = (copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
                           copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue) / corner;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //upper border
            else if (i == 0 && (j > 0 && j < width - 1))
            {
                avgRed = (copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed +
                          copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / border;
                avgGreen = (copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                            copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / border;
                avgBlue = (copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                           copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / border;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //bottom border
            else if (i == height - 1 && (j > 0 && j < width - 1))
            {
                avgRed = (copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed +
                          copy[i - 1][j + 1].rgbtRed) / border;
                avgGreen = (copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                            copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / border;
                avgBlue = (copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                           copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / border;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //left border
            else if ( j == 0 && (i > 0 && i < height - 1))
            {
                avgRed = (copy[i - 1][j].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                          copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / border;
                avgGreen = (copy[i - 1][j].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                            copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / border;
                avgBlue = (copy[i - 1][j].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                           copy[i][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / border;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
            //right border
            else if (j == (width - 1) && (i > 0 && i < height - 1))
            {
                avgRed = (copy[i - 1][j].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                          copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) / border;
                avgGreen = (copy[i - 1][j].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                            copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / border;
                avgBlue = (copy[i - 1][j].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                           copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / border;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);

            }
            //other central pixels
            else
            {
                avgRed = (copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j - 1].rgbtRed +
                            copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed +
                            copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) / middle;
                avgGreen = (copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j - 1].rgbtGreen +
                            copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / middle;
                avgBlue = (copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
                            copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue +
                           copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / middle;

                image[i][j].rgbtRed = round(avgRed);
                image[i][j].rgbtGreen = round(avgGreen);
                image[i][j].rgbtBlue = round(avgBlue);
            }
        }
    }
    return;
}
