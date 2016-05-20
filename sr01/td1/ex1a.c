/* ex1a.c*/

#include <stdio.h>

main ()

{

    int i;

    for (i=48 ; i<=57 ; i++)

        printf("|%3d | %c | \n",i,i);

    for (i=97 ; i<=122 ; i++)

        printf("|%3d | %c | \n",i,i);

    return 0;

}