#include <cs50.h>
#include <cs50.c>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string s = get_string(&s, "Message: ");
    for (int i = 0; i < strlen(s); i++)
    {
        //create an empty array of 8 0's for consistency
        char bit_array[] = {0, 0, 0, 0, 0, 0, 0, 0};
        //start with first letter of string and convert it into ASCIII
        int bitty = (int) s[i];
        int j = 7;
        //continue to check the int and divide down to 0 adding 0's and 1's depending on the remainder
        while (bitty >= 1)
        {

            if (bitty % 2 == 0)
            {
                bit_array[j] = 0;
                bitty = bitty / 2;
                j--;
            }
            else if (bitty % 2 == 1)
            {
                bit_array[j] = 1;
                bitty = (bitty - 1) / 2;
                j--;
            }
        }
        //iterate over the array to print each bit
        for (int k = 0; k <= 7; k++)
        {
            print_bulb(bit_array[k]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
