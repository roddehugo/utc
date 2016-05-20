#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"


Noeud *creerNoeud(char lettre)
{
    //On alloue la mémoire avec la taille d'un pointeur sur Noeud
    Noeud *n = malloc(sizeof(Noeud));
    //On initialise les données du noeud
    n->lettre = lettre;
    n->pere = NULL;
    n->fg = NULL;
    n->fd = NULL;
    n->next = NULL;
    //On renvoie le noeud créé
    return n;
}

ListeNoeud *creerListe()
{
    //On alloue la mémoire avec la taille d'un pointeur sur une ListeNoeud
    ListeNoeud *ln = malloc(sizeof(ListeNoeud));
    //On initialise les données de la liste
    ln->debut = NULL;
    ln->fin = NULL;
    //On renvoie la liste vide créée
    return ln;
}

void genererFeuille(Noeud* pere)
{
    if(!pere)
        return;
    //printf("Pere : %c\n",pere->lettre);
    if(pere->lettre=='A') {
        Noeud *fg = creerNoeud('B');
        fg->pere = pere;
        pere->fg = fg;
        pere->fd = NULL;
        //printf("FG : %c  -- VIDE\n",fg->lettre);
    } else if(pere->lettre=='B') {
        Noeud *fg = creerNoeud('A');
        pere->fg = fg;
        fg->pere = pere;
        Noeud *fd = creerNoeud('B');
        fd->pere = pere;
        pere->fd = fd;
        //On peut faire cette liaison certaine
        fg->next = fd;
        //printf("FG : %c  --  FD : %c\n",fg->lettre,fd->lettre);
    }
}

void libererArbre(Noeud* racine)
{
    if(racine == NULL) {
        return;
    }

    libererArbre(racine->fg);
    libererArbre(racine->fd);
    racine->fg = NULL;
    racine->fd = NULL;
    //printf("Libération de %c\n",racine->lettre);
    free(racine);
}

void afficherArbre(Noeud* racine, ListeNoeud** tab, int cpt)
{
    if ( !racine ) {
        return;
    }
    int i,j,k,ha;
    Noeud *m ;
    Noeud *l ;
    i=0;
    k=0;
    while (tab[i]) {
        m=tab[i]->debut;
        while (m) {
            l=m;
            if (m->lettre=='A') {
                for (j=0; j<(pow(2,cpt-i-1)); j++) {
                    printf(" ");
                }
                printf("%c", m->lettre);
                for (j=0; j<(pow(2,cpt-i-1)-1); j++) {
                    printf(" ");
                }
            } else {
                for (j=0; j<(pow(2,cpt-i-1)); j++) {
                    printf(" ");
                }
                printf("%c", m->lettre);
                for (j=0; j<(pow(2,cpt-i-1)-1); j++) {
                    printf(" ");
                }
                if(l->pere) {
                    ha=0;
                    while(l->lettre!='A') {
                        ha++;
                        l=l->pere;
                    }
                    for (k=0; k<pow(2,ha-1); k++) {
                        for (j=0; j<(pow(2,cpt-i-1)); j++) {
                            printf(" ");
                        }
                        printf(" ");
                        for (j=0; j<(pow(2,cpt-i-1)-1); j++) {
                            printf(" ");
                        }
                    }
                }
            }
            m = m->next;
        }
        printf("\n");
        i++;
    }
}

ListeNoeud *genererListe(ListeNoeud* liste)
{
    if (liste == NULL) {
        printf("La liste en paramètre n'existe pas.\n");
        return NULL;
    } else {
        //On créer la liste des fils que l'on va générer
        ListeNoeud *fils;
        fils=creerListe();
        Noeud *n;
        //On parcourt la liste
        n=liste->debut;
        while(n) {
            genererFeuille(n);
            ajouterFinListe(fils,n->fg);
            ajouterFinListe(fils,n->fd);
            n=n->next;
        }
        return fils;
    }
}

void ajouterFinListe(ListeNoeud* liste, Noeud* feuille)
{
    if (liste == NULL || feuille == NULL) {
        return;
    }

    if (liste->debut == NULL) {
        liste->debut = feuille;
    }

    if (liste->fin != NULL) {
        liste->fin->next = feuille;
    }

    liste->fin = feuille;
}
void supprimerListe(ListeNoeud* liste)
{
    if (liste == NULL) {
        return;
    }

    Noeud *cur = liste->debut;
    Noeud *tmp;

    while (cur != NULL) {
        tmp = cur->next;
        if(cur->pere) {
            cur->pere->fg = NULL;
            cur->pere->fd = NULL;
        }
        free(cur);
        cur = tmp;
    }
    free(liste);
}
void afficherListe(ListeNoeud* liste)
{
    if (liste == NULL) {
        return;
    }

    Noeud *n = liste->debut;
    if (n == NULL) {
        return;
    }

    printf("%c", n->lettre);
    n = n->next;

    while (n != NULL) {
        printf(" -> %c", n->lettre);
        n = n->next;
    }

    printf("\n");
}

int calculerTailleListe(ListeNoeud* liste)
{
    if (!liste) {
        return -1;
    }

    int cpt = 0;
    Noeud *n = liste->debut;

    while (n) {
        cpt++;
        n = n->next;
    }

    return cpt;
}

int calculerTailleArbre(Noeud* racine)
{
    if(!racine)
        return -1;
    int cpt = 0;

    while (racine) {
        cpt++;
        racine = racine->fg;
    }
    return cpt;
}


int calculerNombreFeuille(int n)
{
    int tab[n+1];
    int i;
    for (i=0; i<=n; i++) {
        tab[i]=0;
    }
    return fibo(n, tab);

}

int fibo(int n, int tab[n+1])
{
    if(tab[n] != 0)
        return tab[n];
    else {
        if(n==0 || n==1)
            tab[n]=1;
        else
            tab[n] = fibo(n-1,tab) + fibo(n-2,tab);
        return tab[n];
    }
}

int afficherMenu()
{
    int c;
    printf("\n---------------------- MENU -----------------------\n");
    printf("|  1 - Initialiser un arbre                       |\n" );
    printf("|  2 - Générer un arbre de niveau N               |\n" );
    printf("|  3 - Ajouter un niveau                          |\n" );
    printf("|  4 - Supprimer le dernier niveau                |\n" );
    printf("|  5 - Afficher la liste des feuilles             |\n" );
    printf("|  6 - Afficher l'arbre                           |\n" );
    printf("|  7 - Calculer le nombre de noeuds au niveau N   |\n" );
    printf("|  8 - Calculer avec Fibonacci                    |\n" );
    printf("|  9 - Detruire l'arbre                           |\n" );
    printf("| 10 - Quitter                                    |\n" );
    printf("---------------------------------------------------\n");
    printf("Entrez votre choix : ");
    scanf("%d",&c);
    return c;
}
