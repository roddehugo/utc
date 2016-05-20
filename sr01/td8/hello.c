/*ev1.c -- espace virtuel d'un programme*/
#include <stdio.h>
#include <stdlib.h>

extern int errno;
extern int etext, edata, end;
int tab1[100];
main()
{
    int n,i,j;
    char *buf;
    printf("\n etext= %d  %x", &etext, &etext);
    printf("\n edata= %d  %x", &edata, &edata);
    printf("\n end= %d  %x", &end, &end);
    printf("\n sbrk limite = %d  %x", sbrk(0),sbrk(0));

    n = &edata - &etext;
    printf("\n edata-etext= size init data = %d  %x", n,n);
    n = &end - &edata;
    printf("\n end-edata= size uninit data = %d  %x", n,n);

    printf("\n\n apres malloc \n ");
    buf= (char*) malloc (10000);
    if (buf==NULL) printf("Pb de malloc!!!!\n");

    printf("\n end= %d  %x", &end, &end);
    printf("\n sbrk limite = %d  %x", sbrk(0),sbrk(0));
    n = &end - &edata;
    printf("\n end-edata= size uninit data = %d  %x", n,n);

    printf("\n\n");
    return(0);
}
