#ifndef TP4_tp4_h
#define TP4_tp4_h

typedef struct Noeud {
    char lettre;
    // Arbre
    struct Noeud* pere;
    struct Noeud* fg;
    struct Noeud* fd;
    // Liste
    struct Noeud* next;
} Noeud;

typedef struct ListeNoeud {
    struct Noeud* debut;
    struct Noeud* fin;
} ListeNoeud;

//Fonctions demandées

Noeud *creerNoeud(char);
ListeNoeud *creerListe();
void genererFeuille(Noeud*);
void libererArbre(Noeud*);
void afficherArbre(Noeud*, ListeNoeud**, int);
void ajouterFinListe(ListeNoeud*, Noeud*);
ListeNoeud *genererListe(ListeNoeud*);
void supprimerListe(ListeNoeud*);
void afficherListe(ListeNoeud*);
int calculerTailleListe(ListeNoeud*);
int calculerNombreFeuille(int);

//Fonctions ajoutées

int fibo(int,int*);
int afficherMenu();
int calculerTailleArbre(Noeud*);

#endif
