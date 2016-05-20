struct complexe {
    float x;
    float y;
};

union valeur {
    int entier;
    float reel;
    struct complexe complexe;
};

enum genre {entier, reel, complexe};

typedef struct nombre {
    enum genre  type;
    union valeur valeur;
} nombre;

nombre saisir_nombre();
void afficher_nombre(nombre);