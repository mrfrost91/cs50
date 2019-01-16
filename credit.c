#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cc_digits = 0;
    long cc_number = get_long_long("Enter a credit card number: ");
    long cc_copy = cc_number;
    long x = 1;
    int n, y, z, sum = 0;
    while (cc_copy != 0)
    {
        cc_copy /= 10;
        ++cc_digits;
    }
    for (int i = 0; i < floor(cc_digits / 2); i++)
    {
        x *= 100;
        n = cc_number % x / (x / 10) * 2;
        y = n % 10;
        z = n % 100 / 10;
        sum += z + y;
    }
    x = 10;
    for (int j = 0; j < round(cc_digits / 2); j++)
    {
        n = cc_number % x / (x / 10);
        sum += n;
        x *= 100;
    }
    int checksum = sum % 10;
    int card_type = cc_number / pow(10, cc_digits - 2);
    if ((checksum == 0) && (cc_digits == 16 || cc_digits == 13) && (card_type == 40 || card_type == 41 || card_type == 42
            || card_type == 43 || card_type == 44 || card_type == 45))
    {
        printf("VISA\n");
    }
    else if ((checksum == 0) && (cc_digits == 15) && (card_type == 34 || card_type == 37))
    {
        printf("AMEX\n");
    }
    else if ((checksum == 0) && (cc_digits == 16) && (card_type == 51 || card_type == 52 || card_type == 53 || card_type == 54
             || card_type == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    printf("%f digits\n", cc_digits);
    printf("Check sum is %i\n", sum);
}