#include "mystrlen.h"

int mystrlen(char *s1)
{
    int i=0;
    while(s1[i] != '\0')
        i++;
    return i;
}
