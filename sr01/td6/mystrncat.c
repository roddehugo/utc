#include "mystrncat.h"

void mystrncat(char *s1, char *s2, int n)
{
    int i=0;
    int lens1 = mystrlen(s1);
    int lens2 = mystrlen(s2);

    for(i=0; i<n; i++)
        s2[lens2+i] = s1[(lens1-n)+i];
    s2[lens2+i]='\0';
    //printf("%s\n",s2);
}