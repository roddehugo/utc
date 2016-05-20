#include "mystr.h"

int mystrlen(char *s1)
{
    int i=0;
    while(s1[i] != '\0')
        i++;
    return i;
}

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

void mystrinv(char *s1, char *s2)
{
    int i;
    int len = mystrlen(s1);
    for(i=0; i<len; i++)
        s2[i] = s1[len-i-1];
    s2[i]='\0';
    //printf("%s\n",s2);
}

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

void mystrncpy(char *s1, char *s2, int n)
{
    int i=0;
    int len = mystrlen(s1);
    for(i=0; i<n; i++)
        s2[i] = s1[(len-n)+i];
    s2[i]='\0';
//printf("%s\n",s2);
}

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