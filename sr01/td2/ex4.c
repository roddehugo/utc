#include <stdio.h>
#include "ex4.h"

int main()
{

    afficher_nombre(saisir_nombre());

    return 0 ;
}

void afficher_nombre(nombre nb)
{
    if(nb.type==complexe) {
        if (nb.valeur.complexe.y<0)
            printf("\n%.2f %.2fi\n",nb.valeur.complexe.x,nb.valeur.complexe.y);
        else if (nb.valeur.complexe.y>0)
            printf("\n%.2f + %.2fi\n",nb.valeur.complexe.x,nb.valeur.complexe.y);
        else
            printf("\n%.2f\n",nb.valeur.complexe.x);
    } else if(nb.type==reel) {
        printf("\n%.2f\n",nb.valeur.reel);
    } else {
        printf("\n%d\n",nb.valeur.entier);
    }
}

nombre saisir_nombre()
{
    char rep;
    nombre nb;
    do {
        printf("Entrez le type du nombre : (e)ntier, (r)éel ou (c)omplexe :");
        rep=getchar();
    } while (rep !='e' && rep !='c' && rep != 'r' );
    fflush(stdin);
    switch(rep) {
    case 'e':
        nb.type = entier;
        printf("\nEntrez un nombre entier :");
        scanf("%d",&nb.valeur.entier);
        break;
    case 'r':
        nb.type = reel;
        printf("\nEntrez un nombre réel :");
        scanf("%f",&nb.valeur.reel);
        break;
    case 'c':
        nb.type = complexe;
        printf("\nEntrez la partie réelle du complexe :");
        scanf("%f",&nb.valeur.complexe.x);
        printf("\nEntrez la partie imaginaire du complexe :");
        scanf("%f",&nb.valeur.complexe.y);
        break;
    default :
        printf("Erreur de choix");
        break;
    }
    return nb;
}