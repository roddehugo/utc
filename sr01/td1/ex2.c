/* ex2.c  */

#include <stdio.h>

main()
{

    int i1=6 ,i2, somme ;

    /* -- */

    printf("i2 ?=");

    scanf("%d",&i2);

    /* scanf("%d",i2); --> erreur car il va chercher la valeur située à l'adresse renseignée comme étant i2  */

    somme = i1 + i2 ;

    printf(" Somme : %d\n",somme);

    return 0;
}