#include <stdio.h>
#include "ex1.h"

int main()
{
    int i;
    int tab1[MAX]= {6,4,5,10,8,0,12,1,4,9};
    int tab2[MAX]= {1,2,3,4,5,6,7,8,9,10};
    int tab3[MAX];
    int *p1=tab1, *p2=tab2, *p3=tab3;

    /* rappels pointeurs
     * tab1 <=> tab1[0] <=> *(tab1 + 0)
     * accéder à l'élément i:
     * 	tab1[i]
     * 	*(tab + i)
    */

    for (i=0; i<MAX; i++) {
        *(p3+i)=*(p1+i)+*(p2+((MAX-1)-i));
        printf("%d \t",*(p3+i));
    }
    printf("\n");
    return 0;
}