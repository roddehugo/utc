#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 5

// Vivant : 1
// Mort : 0

void initdamierrand(int damier[N][N])
{
    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            damier[i][j] = rand()%2;
}

void initdamier(int damier[N][N])
{
    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            damier[i][j] = 0;
    //structure baton
    damier[2][1] = 1;
    damier[2][2] = 1;
    damier[2][3] = 1;
}

void afficherdamier(int damier[N][N])
{
    int i,j;
    printf("\n");
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++)
            printf("%c",damier[i][j] ? 'O' : '-');
        printf("\n");
    }
    printf("\n");
}

int calculvoisinvivant(int damier[N][N],int i,int j)
{
    int vivants=0;
    vivants += damier[(N+i-1)%N][(N+j-1)%N];
    vivants += damier[(i-1+N)%N][j];
    vivants += damier[(i-1+N)%N][(j+1)%N];
    vivants += damier[i][(j+N-1)%N];
    vivants += damier[i][(j+1)%N];
    vivants += damier[(i+1)%N][(j-1+N)%N];
    vivants += damier[(i+1)%N][j];
    vivants += damier[(i+1)%N][(j+1)%N];
    return vivants;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int damier[N][N], damiertp1[N][N];
    int i,j, vivants;
    //initialisation aléatoire du damier
    initdamier(damier);
    afficherdamier(damier);
    memcpy(damiertp1, damier, sizeof(damier));
    //traitements des cas
    while(1) {
        for(i=0; i<N; i++) {
            for(j=0; j<N; j++) {
                vivants = calculvoisinvivant(damier,i,j);
                if(damier[i][j]==0 && vivants==3)
                    damiertp1[i][j] = 1;
                if(damier[i][j]==1 && (vivants<2 || vivants>3))
                    damiertp1[i][j] = 0;
            }
        }
        memcpy(damier, damiertp1, sizeof(damier));
        afficherdamier(damier);
    }

}