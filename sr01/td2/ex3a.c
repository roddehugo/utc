#include <stdio.h>
#include "ex3.h"

int main()
{
    complexe c1;
    c1.x=3.4;
    c1.y=0;
    afficher(c1);




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