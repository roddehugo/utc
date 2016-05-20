#include <stdio.h>
#define TAILLE 10

int main()
{
    int i,j;

    for (i=0; i<TAILLE; i++) {
        for (j=0; j<(TAILLE-i-1); j++)
            printf(" ");
        for (j=0; j<(i*2+1); j++)
            printf("*");
        printf("\n");
    }
    for (i=0; i<TAILLE/2; i++) {
        for (j=0; j<(TAILLE-3); j++)
            printf(" ");
        for (j=0; j<4; j++)
            printf("|");
        printf("\n");
    }

    return 0;
}