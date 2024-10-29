#include <cs50.h>
#include <stdio.h>
#include <cs50.c>
#include <stdlib.h>

int only_digits(string arg);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]) == 1)
    {
        string plain_text = get_string(&plain_text, "plaintext: ");
        int shift = atoi(argv[1]);
        for (int j = 0; j < strlen(plain_text); j++)
        {
            if ((int) plain_text[j] >= 65 && (int) plain_text[j] <= 90)
            {
                plain_text[j] = ((int) (plain_text[j] - 65 + shift) % 26) + 65;
            }
            else if ((int) plain_text[j] >= 97 && (int) plain_text[j] <= 122)
            {
                plain_text[j] = ((int) (plain_text[j] - 97 + shift) % 26) + 97;
            }
            else
            {
                plain_text[j] = plain_text[j];
            }            
        }
        printf("ciphertext: %s", plain_text);
    }
    else
    {
        printf("Usage: ./caesar key");
    }
    system("pause");
    return 1;   

}
int only_digits(string arg)
{
    for (int i = 0; i < strlen(arg); i++)
    {
        if (arg[i] < 48 || arg[i] > 57)
        {
            return 0;
        }
    }
    return 1;
}

