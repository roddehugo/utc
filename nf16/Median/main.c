#include <stdio.h>
#include <stdlib.h>
#include "main.h"

listCells initListCells(int t, int s)
{
    Cellule* c=(Cellule*)malloc(sizeof(Cellule*));
    listCells l=(listCells)malloc(sizeof(listCells));
    c->taille = t;
    c->sens = s;
    c->succ = c;
    c->pred = c;
    l->tete = c;
    l->queue = c;
    return l;
}

listCells ajouterTeteList(listCells liste, Cellule* cell)
{
    cell->succ = liste->tete;
    cell->pred = liste->queue;
    liste->tete = cell;
    liste->queue->pred = cell;
    return liste;
}

void afficherListCells(listCells liste)
{
    printf("Tete->");
    Cellule* c = liste->tete;
    do {
        printf("T:%d;S:%d->",c->taille,c->sens);
        c=c->succ;
    } while (c != liste->queue);
    printf("Queue\n\n");
}

void insererCelluleApres(int t,int s, Cellule* c)
{
    Cellule* n=(Cellule*)malloc(sizeof(Cellule*));
    n->taille=t;
    n->sens=s;
    n->pred=c;
    n->succ=c->succ;
    c->succ->pred=n;
    c->succ=n;
}

void insererCelluleAvant(int t,int s, Cellule* c)
{
    Cellule* n=(Cellule*)malloc(sizeof(Cellule*));
    n->taille=t;
    n->sens=s;
    n->succ=c;
    n->pred=c->pred;
    c->pred->succ=n;
    c->pred=n;
}

listCells simulationUneEtape(listCells liste)
{
    Cellule* c=liste->tete;

    do {
        if (c->taille<9) {
            c->taille++;
            c=c->succ;
        } else {
            if (c->sens==1) {
                c->taille=4;
                insererCelluleAvant(5, -1, c);
                c=c->succ;
            } else {
                c->taille=4;
                c=c->succ;
                insererCelluleAvant(5, 1, c);
            }
        }
    } while (c!=liste->queue);
    return liste;
}

listCells simulationNEtapes(listCells liste, int n)
{
    int i;
    for (i=0; i<n; i++) {
        liste=simulationUneEtape(liste);
        afficherListCells(liste);
    }
    return liste;
}

void scinder(listCells liste, listCells lg, listCells ld)
{
    Cellule* c = liste->tete;
    do {
        if (c->sens==1) {
            ld = ajouterTeteList(ld, c);
        } else {
            lg = ajouterTeteList(lg, c);
        }
        c=c->succ;
    } while (c != liste->queue);
}

int main(int argc, const char * argv[])
{
    printf("Bienvenu dans la simulation de croissance cellulaire\n");
    printf("----------------------------------------------------\n");

    listCells liste = initListCells(5, -1);
    simulationNEtapes(liste, 12);
    return 0;
}

