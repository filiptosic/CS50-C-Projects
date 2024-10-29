#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0;
            int new = round(avg);
            image[i][j].rgbtRed = new;
            image[i][j].rgbtGreen = new;
            image[i][j].rgbtBlue = new;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {
            // calculate the new RGB values for the sepia filter
            float sepiaRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            float sepiaGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            float sepiaBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            // check if the calculated value is less than 255, if so assign it to RED
            if (sepiaRed <= 255) {
                image[i][j].rgbtRed = round(sepiaRed);
            }
            // else assign the default capped value of 255
            else {
                image[i][j].rgbtRed = 255;
            }
            // check if the calculated value is less than 255, if so assign it to GREEN
            if (sepiaGreen <= 255) {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }
            // else assign the default capped value of 255
            else {
                image[i][j].rgbtGreen = 255;
            }
            // check if the calculated value is less than 255, if so assign it to BLUE
            if (sepiaBlue <= 255) {
            image[i][j].rgbtBlue = round(sepiaBlue);
            }
            // else assign the default capped value of 255
            else {
                image[i][j].rgbtBlue = 255;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
