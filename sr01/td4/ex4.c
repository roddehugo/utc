#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int jeu_ordi(int nb_allum, int prise_max)
{
    int prise = 0;
    int s = 0;
    float t = 0;
    s = prise_max + 1;
    t = ((float) (nb_allum - s)) / (prise_max + 1);
    while (t != floor (t)) {
        s--;
        t = ((float) (nb_allum-s)) / (prise_max + 1);
    }
    prise = s - 1;
    if (prise == 0)
        prise = 1;
    printf("\nOrdinateur a pris %d allumettes : ",prise);
    return prise;
}

int jeu_joueur(int prise_max)
{
    int prise = 0;
    while(prise<1 || prise>prise_max) {
        printf("\nEntrer le nombre d'allumettes à prendre [1,%d] : ",prise_max);
        scanf("%d",&prise);
    }
    return prise;
}

void afficher_allumettes(int nb_allum)
{
    int i;
    printf("\n");
    for(i=0; i<nb_allum; i++)
        printf("o");
    printf("\n");
    for(i=0; i<nb_allum; i++)
        printf("|");
    printf("\n");
}

int main()
{
    int nb_max_d=0; /*nbre d'allumettes maxi au départ*/
    int nb_allu_max=0; /*nbre d'allumettes maxi que l'on peut tirer*/
    int qui=-1; /*qui joue? 0=Nous --- 1=PC*/
    int prise=0; /*nbre d'allumettes prises par le joueur*/
    int nb_allu_rest=0; /*nbre d'allumettes restantes*/

    while(nb_max_d<10 || nb_max_d>60) {
        printf("\nEntrer le nombre d'allumettes maximum [10,60] : ");
        scanf("%d",&nb_max_d);
    }

    while(nb_allu_max<1 || nb_allu_max>nb_max_d) {
        printf("\nEntrer le nombre d'allumettes prenable par coup [1,%d] : ",nb_max_d);
        scanf("%d",&nb_allu_max);
    }

    while(qui!=0 && qui!=1) {
        printf("\nQui commence la partie ? (0:joueur,1:ordi) :");
        scanf("%d",&qui);
    }

    //initialisation du nombre d'allumettes restantes
    nb_allu_rest=nb_max_d;
    afficher_allumettes(nb_allu_rest);
    while(nb_allu_rest>1) {
        if(qui==1)
            nb_allu_rest -= jeu_ordi(nb_allu_rest,nb_allu_max);
        else
            nb_allu_rest -= jeu_joueur(nb_allu_max);
        afficher_allumettes(nb_allu_rest);
        qui = qui ? 0 : 1;
    }
    if(qui==1)
        printf("\nOrdinateur a perdu !! Bravo !\n");
    else
        printf("\nJoueur a perdu !! Dommage !\n");
    return 0;
}