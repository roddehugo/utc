#include <stdio.h>
#include "ex2.h"

int main ()
{

    int Tab[MAX] ;
    int i ;
    for (i=0 ; i<MAX ; i++) {
        Tab[i] = i + VAL;
        printf("La valeur de la %d ème case du tableau est : %d \n ",i,Tab[i]);
    }

    return 0 ;
}
