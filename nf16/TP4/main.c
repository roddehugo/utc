#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main(int argc, const char * argv[])
{

    int taille = -1;
    Noeud *racine = NULL; // Le noeud racine de l'arbre
    ListeNoeud **tabListe; // Le tableau contenant les listes de noeud de chaque niveau de l'arbre
    int continuer = 1; // Pour quitter
    int nb = 0;

    while(continuer) {
        int c = afficherMenu();
        if(racine)
            taille = calculerTailleArbre(racine);
        switch(c) {
        case 1:
            racine = creerNoeud('A');
            tabListe = (ListeNoeud**) malloc(sizeof(ListeNoeud));
            tabListe[0] = creerListe();
            tabListe[0]->debut = racine;
            tabListe[0]->fin = racine;
            printf("Arbre initialisé\n");
            break;
        case 2:
            printf("Combien de niveaux faut-il générer ? ");
            scanf("%d", &nb);

            //Suppression de l'ancien arbre
            printf("Suppression de l'ancien arbre.\n");
            libererArbre(racine);
            racine = NULL;

            //Création du nouvel arbre
            racine = creerNoeud('A');

            tabListe = (ListeNoeud**) malloc(sizeof(ListeNoeud)*nb);
            tabListe[0] = creerListe();
            tabListe[0]->debut = racine;
            tabListe[0]->fin = racine;

            int i;

            afficherListe(tabListe[0]);
            for (i = 1; i < nb; i++) {
                tabListe[i] = genererListe(tabListe[i-1]);
                afficherListe(tabListe[i]);
            }

            break;
        case 3:
            if(tabListe && tabListe[0] && taille != -1) {
                //Si on a bien une liste on génère la liste suivante
                tabListe = (ListeNoeud **) realloc((ListeNoeud **)tabListe, sizeof(ListeNoeud)*taille);
                tabListe[taille] = genererListe(tabListe[taille-1]); // Le tableau est indicé en partant de 0
                printf("Le niveau a bien été ajouté");
            } else
                printf("Il faut avoir une liste créée.\n");

            break;
        case 4:
            if(tabListe && tabListe[0] && taille != -1) {
                //Si on a bien une liste on supprime la dernière liste
                supprimerListe(tabListe[taille-1]); // Le tableau est indicé en partant de 0
                if(taille == 1) {
                    libererArbre(racine);
                    free(tabListe);
                    racine=NULL;
                }
                printf("Le dernier niveau a bien été supprimé.\n");
            } else
                printf("Il faut avoir une liste créée.\n");

            break;
        case 5:
            if(tabListe && tabListe[0] && taille != -1) {
                //Si on a bien une liste on affiche la dernière liste
                afficherListe(tabListe[taille-1]); // Le tableau est indicé en partant de 0
            } else
                printf("Il faut avoir une liste créée.\n");

            break;
        case 6:
            //Si on a bien un arbre on l'affiche
            if(racine && taille != -1)
                afficherArbre(racine, tabListe, taille);
            else
                printf("Il faut avoir un arbre initialisé.\n");

            break;
        case 7:
            printf("Entrez le niveau à calculer:\n");
            scanf("%d",&nb);
            if(nb <= taille)
                printf("Le nombre de noeud au niveau %d est : %d\n",nb,calculerTailleListe(tabListe[nb]));
            else
                printf("Le niveau n'existe pas.\n");

            break;
        case 8:
            printf("Entrez le niveau à calculer avec Fibonacci:\n");
            scanf("%d",&nb);
            if(nb <= taille)
                printf("Le nombre de noeud au niveau %d est : %d\n",nb,calculerNombreFeuille(nb));
            else
                printf("Le niveau n'existe pas.\n");

            break;
        case 9:
            libererArbre(racine);
            free(tabListe);
            racine = NULL;
            printf("L'arbre a bien été supprimé.\n");

            break;
        case 10:
            libererArbre(racine);
            free(tabListe);
            racine = NULL;
            continuer = 0;

            break;
        default:
            printf("Entrée invalide.\n");
            break;
        }
        if(racine)
            printf("Arbre de %d niveaux.\n",calculerTailleArbre(racine));
    }

    return 0;
}

