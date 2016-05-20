#include <stdio.h>
#include <stdlib.h>
#include "mystr.h"

int main(int argc, char *argv[])
{
    int rep, nombre;
    char s1[80],s2[80];
    char cherche;
    printf("Liste des fonctions disponibles :\n");
    printf("\t1-mystrupdown\n\t2-mystrinv\n\t3-mystrchrn\n\t4-mystrncpy\n\t5-mystrncat\n\t6-mystrlen\n");
    do {
        printf("Quelle fonction utiliser ?");
        scanf("%d",&rep);
    } while(rep < 0 && rep > 6);
    switch(rep) {
    case 1:
        printf("\nEntrez une chaine de caractère : ");
        scanf("%s",s1);
        mystrupdown(s1,s2);
        printf("\nRésultat : %s",s2);
        break;
    case 2:
        printf("\nEntrez une chaine de caractère : ");
        scanf("%s",s1);
        mystrinv(s1,s2);
        printf("\nRésultat : %s",s2);
        break;
    case 3:
        printf("\nEntrez la chaine puis le caractère à chercher : ");
        scanf("%s %c",s1,&cherche);
        printf("\nIl y a %d occurences dans la chaine",mystrchrn(s1,cherche));
        break;
    case 4:
        printf("\nEntrez une chaine de caractère : ");
        scanf("%s",s1);
        printf("\nEntrez le nombre de caractère à copier : ");
        scanf("%d",&nombre);
        mystrncpy(s1,s2,nombre);
        printf("\nRésultat : %s",s2);
        break;
    case 5:
        printf("\nEntrez une chaine de caractère : ");
        scanf("%s",s1);
        printf("\nEntrez une autre chaine de caractère : ");
        scanf("%s",s2);
        printf("\nEntrez le nombre de caractère à concatener : ");
        scanf("%d",&nombre);
        mystrncat(s1,s2,nombre);
        printf("\nRésultat : %s",s2);
        break;
    case 6:
        printf("\nEntrez une chaine de caractère : ");
        scanf("%s",s1);
        printf("\nLongueur de la chaine : %d",mystrlen(s1));
        break;
    }
    printf("\n");
    return 0;
}