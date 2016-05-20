#include <stdio.h>
int main()
{
    int   tab[] = {1, 2, 9, 10, 7, 8, 11};
    int   i, j;
    char  buffer[] = "Voici une chane"
                     " qui se termine "
                     "par un blanc       ";
    char *p;
    int   t[4][3];


    printf("\nbuffer1 : %s$\n\n", buffer);

    for (i=0; i < sizeof tab / sizeof tab[0]; i++)
        printf("tab[%d] = %d\n", i, tab[i]);

    for (p=buffer; *p; p++)
        printf("%s\n", p);

    do {
        p--;
    } while(*p==' ');

    *++p = '\0';
    printf("\nbuffer2 : %s$\n\n", buffer);

    for (i=0; i < 4; i++)
        for (j=0; j < 3; j++)
            t[i][j] = i + j;

    for (i=0; i < 4; i++) {
        for (j=0; j < 3; j++)
            printf("%d ", t[i][j]);
        printf ("\n");
    }
    return 0;
}