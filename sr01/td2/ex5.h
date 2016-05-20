typedef struct etudiant {
    char prenom[80];
    char nom[80];
    int n_compte;
} etudiant;

#define NBETU 2

etudiant saisir_etudiant();
void afficher_etudiant(struct etudiant);
