#include "mystrupdown.h"

void mystrupdown(char *s1, char *s2)
{
    int i=0;
    while(s1[i] != '\0') {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            s2[i] = 'a' + (s1[i] - 'A');
        } else if(s1[i] >= 'a' && s1[i] <= 'z') {
            s2[i] = 'A' + (s1[i] - 'a');
        } else {
            s2[i] = s1[i];
        }
        i++;
    }
    s2[i]='\0';
    //printf("%s\n",s2);
}