// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if(strcmp(fraction, "1/8") == 0)
    {
        return 1;
    }
    else if (strcmp(fraction, "1/4") == 0)
    {
        return 2;
    }
    else if (strcmp(fraction, "3/8") == 0)
    {
        return 3;
    }
    else if (strcmp(fraction, "1/2") == 0)
    {
        return 4;
    }
    else if (strcmp(fraction, "5/8") == 0)
    {
        return 5;
    }
    else if (strcmp(fraction, "3/4") == 0)
    {
        return 6;
    }
    else if (strcmp(fraction, "7/8") == 0)
    {
        return 7;
    }
    else if (strcmp(fraction, "1/1") == 0)
    {
        return 8;
    }
    else
    {
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq = 440.0;
    int note_len = strlen(note);
    int octave = note[note_len - 1];
    octave -= 48;
        if (note[0] == 'C')
        {
            freq /= pow(2.0, 9.0/12.0);
        }
        else if (note[0] == 'D')
        {
            freq /= pow(2.0, 7.0/12.0);
        }
        else if (note[0] == 'E')
        {
            freq /= pow(2.0, 5.0/12.0);
        }
        else if (note[0] == 'F')
        {
            freq /= pow(2.0, 4.0/12.0);
        }
        else if (note[0] == 'G')
        {
            freq /= pow(2.0, 2.0/12.0);
        }
        else if (note[0] == 'A')
        {
            freq = 440;
        }
        else if (note[0] == 'B')
        {
            freq *= pow(2.0, 2.0/12.0);
        }
        else
        {
            return 0;
        }

        if (octave > 4)
        {
            for(int i = 0; i < octave - 4; i++)
            {
                freq *= 2.0;
            }
        }
        else if (octave < 4)
        {
            for(int i = 0; i < 4 - octave; i++)
            {
                freq /= 2.0;
            }
        }

        if (note[1] == '#')
        {
            freq *= pow(2.0, 1.0/12.0);
        }
        else if (note[1] == 'b')
        {
            freq /= pow(2.0, 1.0/12.0);
        }
    int result = round(freq);
    return result;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}