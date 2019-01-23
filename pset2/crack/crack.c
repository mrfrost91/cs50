#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 13)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    int maxKeyLen = 5;
    char salt[3] = {argv[1][0], argv[1][1], '\0'};
    char pass[maxKeyLen];
    int passLength = strlen(pass);
    string resultHash = "";
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' , 'W', 'X', 'Y', 'Z'};
    int alphabet_len = strlen(alphabet);
    long x = 0;
    // iterate over letters in first digit
    for (int i = 0; i < alphabet_len; i++)
    {
        pass[0] = alphabet[i];
        x++;
        resultHash = crypt(pass, salt);

        if (strcmp(argv[1], resultHash) == 0)
        {
            printf("password: %s, %ld iterations\n", pass, x);
            printf("%s, %s\n", resultHash, argv[1]);
            return 0;
        }
    }

    // iterate over first two digits
    for (int i = 0; i < alphabet_len; i++)
    {
        pass[0] = alphabet[i];
        x++;
        for (int j = 0; j < alphabet_len; j++)
        {
            pass[1] = alphabet[j];
            x++;
            resultHash = crypt(pass, salt);
            if (strcmp(argv[1], resultHash) == 0)
            {
                printf("password: %s, %ld iterations\n", pass, x);
                printf("%s, %s\n", resultHash, argv[1]);
                return 0;
            }
        }
}
    // iterate over first three digits
        for (int i = 0; i < alphabet_len; i++)
    {
        pass[0] = alphabet[i];
        x++;
        for (int j = 0; j < alphabet_len; j++)
        {
            pass[1] = alphabet[j];
            x++;
        for (int k = 0; k < alphabet_len; k++)
        {
            pass[2] = alphabet[k];
            x++;
            resultHash = crypt(pass, salt);
            if (strcmp(argv[1], resultHash) == 0)
            {
                printf("password: %s, %ld iterations\n", pass, x);
                printf("%s, %s\n", resultHash, argv[1]);
                return 0;
            }
        }
}
}
    // iterate over first four digits
        for (int i = 0; i < alphabet_len; i++)
    {
        pass[0] = alphabet[i];
        x++;
        for (int j = 0; j < alphabet_len; j++)
        {
            pass[1] = alphabet[j];
            x++;
        for (int k = 0; k < alphabet_len; k++)
        {
            pass[2] = alphabet[k];
            x++;
        for (int l = 0; l < alphabet_len; l++)
        {
            pass[3] = alphabet[l];
            x++;
            resultHash = crypt(pass, salt);
            if (strcmp(argv[1], resultHash) == 0)
            {
                printf("password: %s, %ld iterations\n", pass, x);
                printf("%s, %s\n", resultHash, argv[1]);
                return 0;
            }
        }
}
}
}
    // iterate over all five digits
        for (int i = 0; i < alphabet_len; i++)
    {
        pass[0] = alphabet[i];
        x++;
        for (int j = 0; j < alphabet_len; j++)
        {
            pass[1] = alphabet[j];
            x++;
        for (int k = 0; k < alphabet_len; k++)
        {
            pass[2] = alphabet[k];
            x++;
        for (int l = 0; l < alphabet_len; l++)
        {
            pass[3] = alphabet[l];
            x++;
        for (int m = 0; m < alphabet_len; m++)
            pass[4] = alphabet[m];
            x++;
            resultHash = crypt(pass, salt);
            if (strcmp(argv[1], resultHash) == 0)
            {
                printf("password: %s, %ld iterations\n", pass, x);
                printf("%s, %s\n", resultHash, argv[1]);
                return 0;
            }
        }
}
}
}
}