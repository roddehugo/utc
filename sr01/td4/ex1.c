#include <stdio.h>
#include <string.h>

int main()
{
    int i,nbMaj,nbMin,nbBlanc,nbAutre;
    i=nbMaj=nbMin=nbBlanc=nbAutre=0;
    char chaine[100];
    fgets(chaine,100,stdin);
    while (chaine[i] != '\0') {
        if (chaine[i]>='A' && chaine[i]<='Z')
            nbMaj++;
        else if (chaine[i]>='a' && chaine[i]<='z')
            nbMin++;
        else if (chaine[i]==' ')
            nbBlanc++;
        else nbAutre++;
        i++;
    }
    printf("Longueur de la chaine : %d\n Nombre de majuscule :%d\n Nombre de miniscule :%d\n Nombre d'espace :%d\n Nombre d'autres caractères :%d\n",i-1,nbMaj,nbMin,nbBlanc,nbAutre-1);


    return 0;
}