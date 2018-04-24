// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <string.h>//includes strcmp()
#include <stdlib.h>
#include <math.h>//pow()
#include <ctype.h> //toupper

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO

    int numerator = fraction[0] - '0';
    //printf("numerator%i\n", numerator);

    int denominator = fraction[2] - '0';
    //printf("denominator%i\n", denominator);

    //calculate how many 1/8ths
    int result = numerator * (8 / (denominator));
    //printf("result: %i\n", result);
    return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //  TODO
    const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                            "F#", "G", "G#", "A", "A#", "B"
                           };
    char notes[3];
    int oct;
    bool flat = false;

    if (strlen(note) == 2)
    {
        notes[0] = toupper(note[0]);
        notes[1] =  '\0';
        oct = note[1] - '0';
    }
    else
    {
        notes[0] = toupper(note[0]);
        if (note[1] == 'b')
        {
            flat = true;
            notes[1] =  '\0';
        }
        else
        {
            notes[1] = toupper(note[1]);
            notes[2] =  '\0';
        }
        oct = note[2] - '0';
    }
    //printf("notes :%s\n",notes);
    //printf("oct : %i\n",oct);

    int length = sizeof(NOTES) / sizeof(*NOTES); //length of array
    int posA = 9;
    double n = 0;
    double frequency = 0;
    for (int i = 0; i < length; i++)
    {
        if (!(strcmp(notes, NOTES[i])))
        {
            n = i - posA;//position relative to A
            n = n + (oct - 4) * 12; //adjust for the current octave relative to octave 4
            if (flat)
            {
                n = n - 1;//adjust for flat
            }

            frequency = round(440 * pow(2.00, n / 12.00));
            //printf("%f\n");
        }
    }
    return frequency;
}




// Determines whether a string represents a rest
bool is_rest(string s)
{

    // TODO
    if (!(strcmp(s, "")))//compares s with ""
    {
        return true;

    }
    else
    {
        return false;
    }
}
