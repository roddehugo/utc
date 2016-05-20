#include "mystrncpy.h"

void mystrncpy(char *s1, char *s2, int n)
{
    int i=0;
    int len = mystrlen(s1);
    for(i=0; i<n; i++)
        s2[i] = s1[(len-n)+i];
    s2[i]='\0';
//printf("%s\n",s2);
}
