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
    string key = argv[1];
    int key_len = strlen(key);
    for (int i = 0; i < key_len; i++)
    {
        if (islower(key[i]))
        {
            key[i] -= 97;
        }
        else if (isupper(key[i]))
        {
            key[i] -= 65;
        }
        else
        {
            eprintf("program should have only letters in argument\n");
            return 1;
        }
    }
    string input = get_string("plaintext: ");
    int input_len = strlen(input);
    char cipher[input_len + 1];
    for (int i = 0, j = 0; i < input_len + 1; i++)
    {
        cipher[i] = input[i];
        if (isalpha(input[i]) && islower(input[i]))
        {

            cipher[i] = (cipher[i] + key[j % key_len] - 97) % 26;
            cipher[i] += 97;
            j++;
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            cipher[i] = (cipher[i] + key[j % key_len] - 65) % 26;
            cipher[i] += 65;
            j++;
        }
        else if (i == input_len)
        {
            cipher[i] = '\0';
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}