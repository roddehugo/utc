#include <stdio.h> //include, same as exo 1
#define MAX 25

typedef struct {
    float x;
    float y;
} unPoint;

typedef struct {
    unPoint sommet[3]; //dans la suite du programme du utilise le nom 'tab' et non 'point' + a priori un triangle à 3 sommets chacun avec une abscisse et une ordonnée
    int gris;
    float trans;
} unTriangle; // pas oublier le ;

void initTriangle(unTriangle *tri)
{
    int i,j;
    for(i=0,i<4,i++) { //on commence à 0 dans un tableau !!!!!
        printf("\ndonner l'abscisse du sommet %d de votre triangle\n",i+1); //du coup on met i+1 pour l'utilisateur ;)
        scanf("%d",&tri->sommet[i].x);
        printf("\ndonner l'ordonné du sommet %d de votre triangle\n",i+1);
        scanf("%d",&tri->sommet[i].y);
    }
    printf("Quel gris donnez vous au triangle ?");
    scanf("%d",&tri->gris);
    printf("Donnez le niveau de transparence entre 0 et 1");
    scanf("%f",&tri->trans);
}

void afficheTriangle(unTriangle tri)
{
    int i;
    for(i=1,i<4,i++)
        printf("\nLe points %d du triangle est : x=%d et y=%d",i+1, tri.point[i].x, tri.point[i].y); // pas besoin de & car on lit la valeur, on ne modifie pas
    printf("\nLe niveau de gris est : %d",tri.gris);
    printf("\nLe niveau de transparence est : %f",tri.trans);
}

int intersectionTriangle(unTriangle T1, unTriangle T2, unTriangle *T3)
{
    //connu : dansTriangle(unTriangle T, unPoint P)
    //connu : intersectionPoint(unPoint S1, unPoint S2, unPoint P1, unPoint P2, unPoint *PI)
    //on regarde si les sommets de T2 sont dans T1
    int i, nbpt = 0, sommetDansTriangle = {0,0,0};
    for (i=0; i<3; i++) { //on commence la lecture à 0 dans le tableau
        sommetDansTriangle[i] = dansTriangle(T1,T2.point[i]);
        nbpt += sommetDansTriangle[i]; //On stock quels sommets sont dans le triangle précédent
    }

    if(nbpt == 1) {
        //Bon je ne suis pas sur non plus... il faut tester ts les cas possible...
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
                if(sommetDansTriangle[i]) && i!=j)
                    intersectionPoint(T1.point[i], T1.point[j], T2.point[i], T2.point[j], T3.point[i]);

                    return 1;
                } else
        return 0;
}

void main()
{
    unTriangle t1,t2,t3;
    initTriangle(*t1);
    initTriangle(*t2);
    //Il faut tester les deux cas : t1 dans t2 ou t2 dans t1, cd la figure de l'énoncé, ça change au niveau de la fonction dantTriangle()
    if(intersectionTriangle(t1,t2,*t3)) {
        t3.gris = (1-t1.trans)*t1.gris + t1.trans *( (1-t2.trans) * t2.gris + t2.trans);
        t3.trans = t1.trans * t2.trans;
        afficheTriangle(t3);
    } else if(intersectionTriangle(t2,t1,*t3)) {
        t3.gris = (1-t2.trans)*t2.gris + t2.trans *( (1-t1.trans) * t1.gris + t1.trans);
        t3.trans = t1.trans * t2.trans;
        afficheTriangle(t3);
    } else {
        printf("\nPas de triangle a afficher");
    }
}
