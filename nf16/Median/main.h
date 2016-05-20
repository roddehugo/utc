#ifndef median_main_h
#define median_main_h

typedef struct Cellule {
    int taille;
    int sens;
    struct Cellule* succ;
    struct Cellule* pred;
} Cellule;

typedef struct listCells {
    struct Cellule* tete;
    struct Cellule* queue;
}*listCells;

listCells initListCells(int, int);
listCells ajouterTeteList(listCells, Cellule*);
void afficherListCells(listCells);
listCells simulationUneEtape(listCells);
listCells simulationNEtapes(listCells, int);
void scinder(listCells, listCells, listCells);

#endif
