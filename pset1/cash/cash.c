#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float n;
    int coins = 0;
    do
    {
        n = get_float("How much dollars do you owe: ");
        n = round(n*100);
    }
    while(n < 0);
    while(n >= 25)
    {
        coins++;
        n -= 25;
    }
    while(n >= 10)
    {
        coins++;
        n -= 10;
    }
    while(n >= 5)
    {
        coins++;
        n -= 5;
    }
    while(n > 0)
    {
        coins++;
        n -= 1;
    }
    printf("The change is %i coins\n", coins);
}