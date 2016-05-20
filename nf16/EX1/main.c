#include <stdio.h>
#include <stdlib.h> //Ce sont des includes pas des define
#define MAX 25

void CO2Horaire(int tab[])
{
    int heure;
    for(heure=0; heure<24; heure++) { //pas de ;
        printf("\nDonnez la concentration de CO2 à %dH:OO",heure); //la virgute et heure est de type decimal
        scanf("%d",&tab[heure]); // %d et non &d ; il faut mettre le & devant tab, car on accède à UN ELEMENT du tableau, cet element n'est pas un pointeut mais bien une variable de valeur
    }
} //fonction non fermée

void MoyenneGlissante(int tab[],int moyG[])
{
    int heure,plageH=1; //pk tu commences à 1 et pas à 0 ?
    for (heure=0; heure<16; heure++) {
        moyG[plageH]=(tab[heure]+tab[heure+1]+tab[heure+2]+tab[heure+3]+tab[heure+4]+tab[heure+5]+tab[heure+6]+tab[heure+7]+tab[heure+8])/8;
        plageH++;
    }
}//fonction non fermée

int ValeurMax(int tab[],int tailletab)
{
    int i, max = tab[0];
    for (i=0; i<tailletab-1; i++) { //Attention c'est un 0 et pas la lettre o pour i=
        if(tab[i] > max ) //Ca ne serait pas plutot tab[i] > max
            max=tab[i];
    }
    return max;
    // car le tableau n'est pas trié à la base, il faut donc le parcourir entierement avant de retourner la valeur
}

int main()
{
    int tab[MAX], moyG[MAX], moy;
    CO2Horaire(tab);
    MoyenneGlissante(tab,moyG);
    printf("\nLa concentration max de CO2 dans la journée est : %d",ValeurMax(tab,25)); //25 ici non ?
    printf("\nLa moyenne glissante max est : %d",ValeurMax(moyG,25)); //pareil
    return 0;
}