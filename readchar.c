#include <stdio.h>
#include <stdlib.h>

char change_array (char array[], char letter, int location);
int change_int (int *randy);
int main() {
    int random = 8;
    int *p = &random;
    char message[100];
    char letter_to_change;
    int location_of_letter;
    printf("What is the message?\n");
    gets(message);
    printf("Which letter would you like to insert?\n");
    letter_to_change = getchar();
    printf("What is the index of the letter you wish to change?\n");
    scanf("%d", &location_of_letter);
    change_array(message, letter_to_change, location_of_letter);
    printf("%s\n", message);
    printf("%d\n", *p);
    printf("%p\n", *p);
    change_int(p);
    printf("%d\n", random);
    printf("%d\n", *p);
    printf("%p\n", *p);
}
int change_int (int *randy)
{
    *randy = 9;

}
char change_array (char array[], char letter, int location)
{
    array[location] = letter;
    return (int) array;
}