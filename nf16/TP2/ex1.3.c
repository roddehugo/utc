#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Exercie 3 */
void saisieMatrice(int**,int,int);
void afficheMatrice(int**, int, int);
int determinant(int**,int, int);
int** extraire_sous_matrice(int**,int, int, int);

void saisieMatrice(int **m,int n)
{
    int i,j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = (int) rand()%21-10;
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void afficheMatrice(int **m,int n)
{
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int** extraire_sous_matrice(int **m,int n, int l, int c)
{
    int i,j,x,y;
    x=y=0;
    int **sm = (int **)malloc(sizeof(int)*(n-1));
    for (i = 0; i < n-1; i++) {
        sm[i] = (int *)malloc(sizeof(int)*(n-1));
    }
    for(i=0; i<n; i++) {
        if(i!=l) {
            for(j=0; j<n; j++) {
                if(j!=c) {
                    sm[x][y]=m[i][j];
                    y++;
                }
            }
            x++;
            y=0;
        }
    }
    afficheMatrice(sm,n-1);
    return sm;
}

int determinant(int **m, int n)
{
    int det = 0,i;
    if(n==1) {
        det = m[0][0];
    } else {
        for (int i = 0; i < n; i++) {
            if (i%2==0) {
                det += m[i][0]*determinant(extraire_sous_matrice(m,n,i,0),n-1);
            } else {
                det += -1*m[i][0]*determinant(extraire_sous_matrice(m,n,i,0),n-1);
            }
        }
    }
    return det;
}

int main()
{
    int i, n;
    srand(time(NULL));
    printf("Taille de la matrice carrée : \n");
    scanf("%d",&n);

    int **m = (int **)malloc(sizeof(int)*n);
    for (i = 0; i < n; ++i) {
        m[i] = (int *)malloc(sizeof(int)*n);
    }

    if(m == NULL) {
        printf("Allocation impossible pour la matrice");
        return 0;
    }
    saisieMatrice(m,n);
    printf("Le determinant : %d\n",determinant(m,n));
    free(m);

    return 0;
}

