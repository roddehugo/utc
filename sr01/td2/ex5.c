#include <stdio.h>
#include "ex5.h"

int main()
{
    etudiant liste_etudiant[NBETU];
    int i;
    for(i=0; i<NBETU; i++) {
        liste_etudiant[i] = saisir_etudiant();
    }
    return 0 ;
}

etudiant saisir_etudiant()
{
    etudiant etu;
    printf("\nNom : ");
    scanf("%s",&etu.nom);
    printf("\nPrénom : ");
    scanf("%s",&etu.prenom);
    printf("\nNum de compte : ");
    scanf("%d",&etu.n_compte);
    afficher_etudiant(etu);
    return etu;
}

void afficher_etudiant(etudiant etu)
{
    printf("\nNom : %s - Prénom : %s - Num de compte : %3d",etu.nom,etu.prenom,etu.n_compte);
}
