#include <stdio.h>

void cone(int taille, int nbre)
{
    int i,j,k;
    for (i=0; i<taille; i++) {
        for (k=0; k<nbre; k++) {
            for (j=0; j<(taille-i-1); j++)
                printf(" ");
            for (j=0; j<(i*2+1); j++)
                printf("*");
            for (j=0; j<(taille-i+1); j++)
                printf(" ");
        }
        printf("\n");
    }
}
void tronc(int taille, int nbre)
{
    int i,j,k;
    for (i=0; i<taille/2; i++) {
        for (k=0; k<nbre; k++) {
            for (j=0; j<(taille-3); j++)
                printf(" ");
            for (j=0; j<4; j++)
                printf("|");
            for (j=0; j<(taille); j++)
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    cone(10,5);
    tronc(10,5);

    return 0;
}