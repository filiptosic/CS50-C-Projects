#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string convert(string cipher, string plaintext);
int check_duplicates(string cipher);
int string_validation(string cipher, int string_length);
int main(int argc, string argv[])
{
    // checks that only 2 command line args are received, exits if not
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }
    string cipher = argv[1];
    int string_length = strlen(cipher);
    // checks for length of cipher
    if (string_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // if cipher and cipher length are valid prompts for plaintext and converts to cipher
    else if (string_validation(cipher, string_length) == 0 && check_duplicates(cipher) == 0)
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", convert(cipher, plaintext));
    }
    else
    {
        return 1;
    }
}
// checks that the cipher is fully alphabetical
int string_validation(string cipher, int string_length)
{
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(cipher[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
// checks for duplicates, returns 0 if there are none
int check_duplicates(string cipher)
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(cipher[i]) == tolower(cipher[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}
string convert(string cipher, string plaintext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // convert all of the lowercase letters in the string
        // tolower() function is used because cipher is received in all capital letters
        if (isalpha(plaintext[i]) != 0 && islower(plaintext[i]) != 0)
        {
            int new = plaintext[i] - 97;
            plaintext[i] = tolower(cipher[new]);
        }
        // convert all of the uppercase letters in the string
        else if (isalpha(plaintext[i]) != 0 && isupper(plaintext[i]) != 0)
        {
            int new = plaintext[i] - 65;
            plaintext[i] = toupper(cipher[new]);
        }
    }
    return plaintext;
}
