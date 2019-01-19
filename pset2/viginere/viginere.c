#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        eprintf("program shouldn't have more than one argument\n");
        return 1;
    }
    else if (argc == 1)
    {
        eprintf("program should have one argument as a cipher key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string input = get_string("plaintext: ");
    int input_len = strlen(input);
    char cipher[input_len + 1];
    for (int i = 0; i < input_len + 1; i++)
    {
        cipher[i] = input[i];
        if (isalpha(input[i]) && islower(input[i]))
        {
            cipher[i] = (cipher[i] + key - 97) % 26;
            cipher[i] += 97;
            /*input[i] = cipher[i];*/
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            cipher[i] = (cipher[i] + key - 65) % 26;
            cipher[i] += 65;
            /*input[i] = cipher[i];*/
        }
        else if (i == input_len)
        {
            cipher[i] = '\0';
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}