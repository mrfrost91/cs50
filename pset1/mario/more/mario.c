#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Set the height: ");
    }
    while (n > 23 || n < 0);
    for (int i = 0, y = n, z = 1; i < n; i++)
    {
        y = n - i;
    for (int j = 0; j < y-1; y--)
    {
        printf(" ");
    }
    for (int k = 0; k < z; k++)
    {
        printf("#");
    }
    for (int l = 0; l < 2; l++)
    {
    printf(" ");
    }
    for (int m = 0; m < z; m++)
    {
        printf("#");
    }
    printf("\n");
    z++;
    }
}