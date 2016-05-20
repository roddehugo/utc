#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Exercie 3 */
void saisieMatrice(int**,int,int);
void afficheMatrice(int**, int, int);
void afficheVecteur(int*, int);
int matriceCreuse(int**,int*, int, int);

int main()
{
    int i, j ,k;
    srand(time(NULL));
    int c,l,n;
    printf("Nombre de lignes de M: \n");
    scanf("%d",&l);
    printf("Nombre de colonnes de M : \n");
    scanf("%d",&c);

    int **m1 = (int **)malloc(sizeof(int)*l);
    for (i = 0; i < l; ++i) {
        m1[i] = (int *)malloc(sizeof(int)*c);
    }
    int *v = (int *)malloc(sizeof(int)*c*l);
    if(m1 == NULL || v==NULL) {
        printf("Allocation impossible pour la matrice");
        return 0;
    }
    saisieMatrice(m1,l,c);
    printf("La matrice est-elle creuse ? : %s\n",matriceCreuse(m1,v,l,c) ? "oui" : "non");
    afficheVecteur(v,l*c);
    free(m1);

    return 0;
}

void saisieMatrice(int **m,int lig, int col)
{
    int i,j;
    printf("Ligne : %d\nColonne : %d\n",lig,col);
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            m[i][j] = (int) rand()%21-10;
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void afficheMatrice(int **m, int lig, int col)
{
    int i,j;
    printf("La matrice :\n");
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void afficheVecteur(int *v,int n)
{
    int i;
    printf("Le Vecteur :\n");
    for (i = 0; i < n; i++) {
        printf("%d\t",v[i]);
    }
    printf("\n");
}

int matriceCreuse(int **m, int *v, int lig, int col)
{
    int i,j,nbZero;
    nbZero=0;
    for (i=0; i<lig; i++) {
        for (j=0; j<col; j++) {
            if (m[i][j]==0) {
                nbZero++;
            } else {
                v[i*col+j] = m[i][j];
            }
        }
    }
    return (nbZero>(0.8*col*lig)) ? 1 : 0;
}
