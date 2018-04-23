#include <cs50.h>
#include <stdio.h>
#include "helpers.c"

bool is_rest(string s);
int duration(string fraction);
int frequency(string note);
int main(void)
{
    //string s = get_string("");
    //bool rest = is_rest(s);
    //printf("%s", rest ? "true" : "false");//if rest print true else print false
    //string userFrac = get_string("Enter a fraction: ");
    //int userDuration = duration(userFrac);
    //printf("%i\n", userDuration);
    string userNote = get_string("Enter a note: ");
    int userFreq =  frequency(userNote);
    printf("%d\n", userFreq);


}

