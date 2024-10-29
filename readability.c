#include <cs50.h>
#include <cs50.c>
#include <stdio.h>

int count_letters(string word);
int count_words(string word);
int count_sentences(string word);

int main(void)
{
    string input = get_string(&input, "Text: ");

    //printf("%d letters\n", count_letters(input));
    
    //printf("%d words\n", count_words(input));
    
    //printf("%d sentences\n", count_sentences(input));
    
    float L = (count_letters(input) / (float) count_words(input)) * 100;

    float S = (count_sentences(input) / (float) count_words(input)) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //printf("%.0f index value\n", round(index));
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
    system("pause");
    return 0;


}

int count_letters(string word) {
    int letters = 0;
    for (int i = 0; i < strlen(word); i++) {

        if(((int) word[i] >= 65 && (int) word[i] <= 90) || ((int) word[i] >= 97 && (int) word[i] <= 122)) {

            letters += 1;
        
        }
    }
    return letters;
}

int count_words(string word) {

    int word_count = 1;

    for (int j = 0; j < strlen(word); j++) {

        if (word[j] == 32) {

            word_count += 1;
        }
    }
    return word_count;

}

int count_sentences(string word) {
    int sentence_count = 0;
    for (int k = 0; k < strlen(word); k++) {

        if (word[k] == 46 || word[k] == 33 || word[k] == 63) {

            sentence_count += 1;

        }
    }
    return sentence_count;
}