/* ex1c.c*/

#include <stdio.h>

main ()

{

    char i;

    for(i='0' ; i<='9' ; i++)

        printf("|%3d | %c | \n",i,i);

    for (i='a' ; i<='z' ; i++)

        printf("|%3d | %c | \n",i,i);

    for (i='A' ; i<='Z' ; i++)

        printf("|%3d | %c | \n",i,i);

    return 0;

}