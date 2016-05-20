#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
#define NMAX 20
#define CMAX 60

typedef struct Un_Tableau_Entier {
    int tab[NMAX];
    int ncase;
} Un_Tableau_Entier;

typedef struct Menu {
    char tab[NMAX][CMAX];
    int nitem;
} Menu;

typedef struct Tonneau {
    float d;
    float D;
    float L;
    enum {vin, vinaigre, biere, huile} contenu;
} Tonneau;

float Volume (Tonneau t)
{
    return PI*t.L*(t.d/2+2/3*(t.D/2-t.d/2))*2;
}

int main(int argc, char const *argv[])
{
    Tonneau t;
    t.d = 2.36;
    t.D = 3.25;
    t.L = 5.28;
    printf("\nLe volume est : %f\n" ,Volume(t));
    return 0;
}
