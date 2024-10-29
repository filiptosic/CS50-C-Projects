#include <cs50.h>
#include <stdio.h>

int num_digits(long cc_num);
bool sum_digits(long cc_num, int cc_length);
string card_type(int cc_length, long cc_num);
int main(void)
{
    long card_number;
    card_number = get_long("Number: ");
    int card_length = 0;
    card_length = num_digits(card_number);
    if (sum_digits(card_number, card_length) == true)
    {
        printf("%s", card_type(card_length, card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}

int num_digits(long cc_num)
{
    int num_length = 0;
    while (cc_num > 0)
    {
        cc_num /= 10;
        num_length++;
    }
    return num_length;
}
bool sum_digits(long cc_num, int cc_length)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < cc_length; cc_num /= 10, i++)
    {
        if (i % 2 == 1)
        {
            int current = 2 * (cc_num % 10);
            if (current > 9)
            {
                current = (current % 10) + 1;
            }
            sum1 += current;
        }
        else
            (sum2 += cc_num % 10);
    }
    int total = sum1 + sum2;
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string card_type(int cc_length, long cc_num)
{
    long first_digit = cc_num;
    while (first_digit >= 10)
    {
        first_digit /= 10;
    }
    long first_two = cc_num;
    while (first_two >= 100)
    {
        first_two /= 10;
    }
    if (cc_length == 13)
    {
        return "VISA\n";
    }
    else if (cc_length == 15 && (first_two == 34 || first_two == 37))
    {
        return "AMEX\n";
    }
    else if (cc_length == 16 && first_digit == 4)
    {
        return "VISA\n";
    }
    else if (cc_length == 16 && (first_two >= 51 && first_two <= 55))
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}
