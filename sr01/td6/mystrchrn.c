#include "mystrchrn.h"

int mystrchrn(char *s, char c)
{
    int i=0, occur=0;
    while(s[i] != '\0') {
        if(s[i] == c)
            occur++;
        i++;
    }
    //printf("%d\n",occur);
    return occur;
}