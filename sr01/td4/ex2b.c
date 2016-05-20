#include <stdio.h>
#define TAILLE 10
#define NBRE 3

int main()
{
    int i,j,k;

    for (i=0; i<TAILLE; i++) {
        for (k=0; k<NBRE; k++) {
            for (j=0; j<(TAILLE-i-1); j++)
                printf(" ");
            for (j=0; j<(i*2+1); j++)
                printf("*");
            for (j=0; j<(TAILLE-i+1); j++)
                printf(" ");
        }
        printf("\n");
    }
    for (i=0; i<TAILLE/2; i++) {
        for (k=0; k<NBRE; k++) {
            for (j=0; j<(TAILLE-3); j++)
                printf(" ");
            for (j=0; j<4; j++)
                printf("|");
            for (j=0; j<(TAILLE); j++)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}