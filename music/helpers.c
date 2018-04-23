// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <string.h>//includes strcmp()
#include <stdlib.h>
#include <math.h>//pow()

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    //printf("fraction: %s\n", fraction);

    int numerator = fraction[0] - '0';
    //printf("numerator%i\n", numerator);

    int denominator = fraction[2] - '0';
     //printf("denominator%i\n", denominator);

    //calculate how many 1/8ths
    int result = numerator * (8/(denominator));
    //printf("result: %i\n", result);
    return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //  TODO
    // const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
    //                     "F#", "G", "G#", "A", "A#", "B"
    //                   };
    int n = 0;
    char inNote = note[0];
    char oct = note[1];
    switch(note[0]) {
        case 'C' :
            n = -9;
            break;
        case 'C#' :
            //sscanf(note, "%1c%1i", &Note, &Octave);
            n = -8;
            break;
        case 'D' :
            n = -7;
            break;
        case 'D#' :
            n = -6;
            break;
        case 'E' :
            n = -5;
            break;
        case 'F' :
            n = -4;
            break;
        case 'F#' :
            n = -3;
            break;
        case 'G' :
            n = -2;
            break;
        case 'G#' :
            n = -1;
            break;
        case 'A#' :
            n = 1;
            break;
        case 'B' :
             n = 2;
          default :
            printf("n is:  %i\n",n);
            return 0;
       }


        if (strlen(note) == 2)
        {

            printf("Note%s\n", note);
            printf("FirstLetter: %c\n", inNote);
            printf("SecondLetter: %c\n", oct);

            double baseNote = 440.00;//relates to AS
            int semitone = 2 * pow(n, 12);
            printf("%g\n", semitone);//g is placeholder for double
            int freq = semitone * baseNote;

        }

        else
        {
            char inNote = note[0];
            char acc = note[1];
            char oct = note[2];
            printf("FirstLetter: %c\n", inNote);
            printf("SecondLetter: %c\n", acc);
            printf("ThirdLetter: %c\n", oct);
        }
          return 0;
    }
    return 0;

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
