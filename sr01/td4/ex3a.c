#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Exercie 3 */
void saisieMatrice(int**,int,int);
void afficheMatrice(int**, int, int);
void matriceInfo(int**,int, int);

int main()
{
    int i, j ,k;
    srand(time(NULL));
    int m,l,n;
    printf("Nombre de lignes de M: \n");
    scanf("%d",&m);
    printf("Nombre de colonnes de M : \n");
    scanf("%d",&l);

    int **m1 = (int **)malloc(sizeof(int)*m);
    for (i = 0; i < m; ++i) {
        m1[i] = (int *)malloc(sizeof(int)*l);
    }
    if(m1 == NULL) {
        printf("Allocation impossible pour la matrice");
        return 0;
    }
    saisieMatrice(m1,m,l);
    matriceInfo(m1,m,l);
    free(m1);

    return 0;
}

void saisieMatrice(int **m,int lig, int col)
{
    int i,j;
    printf("Col : %d\nLig : %d\n",col,lig);
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            m[i][j] = (int) rand()%21-10;
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void afficheMatrice(int **m,int col, int lig)
{
    int i,j;
    for (i = 0; i < col; i++) {
        for (j = 0; j < lig; j++) {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void matriceInfo(int **m,int col, int lig)
{
    int i,j,nbPos,nbNeg,nbZero,max,min;
    nbPos=nbNeg=nbZero=0;
    max=min=m[0][0];
    for (i=0; i<col; i++) {
        for (j=0; j<lig; j++) {
            if (m[i][j]<0)
                nbNeg++;
            else if (m[i][j]>0)
                nbPos++;
            else
                nbZero++;
            max = (m[i][j]>max) ? m[i][j] : max;
            min = (m[i][j]<min) ? m[i][j] : min;
        }
    }
    if (nbZero>(0.8*col*lig))
        printf("Matrice creuse !\n");
    printf("Nombre d'éléments positifs :%d\n",nbPos);
    printf("Nombre d'éléments négatifs :%d\n",nbNeg);
    printf("Nombre de zéro :%d\n",nbZero);
    printf("Le max : %d\nLe min : %d\n",max,min);


}
