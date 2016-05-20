#include <stdio.h>
#include "ex1.h"

int main()
{
    int i;
    int tab1[MAX]= {6,4,5,10,8,0,12,1,4,9};
    int tab2[MAX]= {1,2,3,4,5,6,7,8,9,10};
    int tab3[MAX];
    for (i=0; i<MAX; i++) {
        tab3[i]=tab1[i]+tab2[(MAX-1)-i];
        printf("%d \t",tab3[i]);
    }
    printf("\n");
    return 0;
}