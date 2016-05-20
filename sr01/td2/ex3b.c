#include <stdio.h>
#include "ex3.h"

int main()
{
    complexe c1,c2;
    c1.x=3.4;
    c1.y=-5.4;
    c2.x=1.23;
    c2.y=85.0;
    afficher(c1);
    afficher(c2);

    afficher(somme(c1,c2));
    afficher(produit(c1,c2));

    return 0 ;
}

void afficher(complexe c)
{
    if (c.y<0)
        printf("%.2f %.2fi",c.x,c.y);
    else if (c.y>0)
        printf("%.2f + %.2fi",c.x,c.y);
    else
        printf("%.2f",c.x);
    printf("\n");
}

complexe somme(complexe c1 , complexe c2)
{
    complexe s;
    s.x = c1.x + c2.x;
    s.y = c1.y + c2.y;
    return s;
}

complexe produit(complexe c1, complexe c2)
{
    complexe p;
    p.x = c1.x*c2.x - c1.y*c2.y;
    p.y = c1.y*c2.x + c1.x*c2.y;
    return p;
}