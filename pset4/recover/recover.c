#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Couldn't open %s.\n", infile);
        return 2;
    }
    char filename[50];
    BYTE buffer[BLOCK_SIZE];
    int jpegFound = 0;
    int jpegCount = 0;
    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 && jpegFound == 0)
        {
            sprintf(filename, "%03i.jpg", jpegCount);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Couln't create %s.\n", filename);
                return 3;
            }
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            jpegFound++;
        }
        if (jpegFound == 2)
        {
            fclose(img);
            jpegCount++;
            jpegFound--;
            sprintf(filename, "%03i.jpg", jpegCount);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Couln't create %s.\n", filename);
                return 3;
            }
        }
        if (jpegFound == 1)
        {
            fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }
    fclose(img);
    fclose(inptr);
    return 0;
}