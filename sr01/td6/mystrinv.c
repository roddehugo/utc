#include "mystrinv.h"

void mystrinv(char *s1, char *s2)
{
    int i;
    int len = mystrlen(s1);
    for(i=0; i<len; i++)
        s2[i] = s1[len-i-1];
    s2[i]='\0';
    //printf("%s\n",s2);
}