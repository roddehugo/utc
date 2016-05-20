#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp1.h"

int main()
{
    int i, j ,k;
    srand(time(NULL));
    printf("Multiplication de matrice !\n");
    int m,l,n;
    printf("Nombre de lignes de M1: \n");
    scanf("%d",&m);
    printf("Nombre de colonnes de M1 et lignes de M2 : \n");
    scanf("%d",&l);
    printf("Nombre de colonnes de M2 : \n");
    scanf("%d",&n);

    int **m1 = (int **)malloc(sizeof(int)*m);
    for (i = 0; i < m; ++i) {
        m1[i] = (int *)malloc(sizeof(int)*l);
    }

    int **m2 = (int **)malloc(sizeof(int)*l);
    for (j = 0; j < l; ++j) {
        m2[j] = (int *)malloc(sizeof(int)*n);
    }

    int **m3 = (int **)malloc(sizeof(int)*m);
    for (k = 0; k < m; ++k) {
        m3[k] = (int *)malloc(sizeof(int)*n);
    }

    saisieMatrice(m1,m,l);
    saisieMatrice(m2,l,n);
    produitMatrice(m1,m2,m3,m,l,n);
    afficheMatrice(m3,m,n);
    free(m1);
    free(m2);
    free(m3);

    return 0;
}

void saisieMatrice(int **m,int lig, int col)
{
    int i,j;
    printf("Col : %d\nLig : %d\n",col,lig);
    for (i = 0; i < lig; ++i) {
        for (j = 0; j < col; ++j) {
            m[i][j] = (int) rand()%100 + 1;
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void afficheMatrice(int **m,int col, int lig)
{
    int i,j;
    for (i = 0; i < col; ++i) {
        for (j = 0; j < lig; ++j) {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void produitMatrice(int **m1, int **m2, int **m3, int m, int l, int n)
{
    int somme;
    int i, j ,k;

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            somme = 0;
            for (k = 0; k < l; ++k) {
                somme += m1[i][k]*m2[k][j];
            }
            m3[i][j] = somme;
        }
    }
}
