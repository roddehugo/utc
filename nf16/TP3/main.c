#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main()
{
    char str[MAX];
    List liste;
    initialize(&liste);
    printf("Entrez un nombre :\n");
    scanf("%s", str);
    insert_empty_list(&liste, str);
    display(&liste);
    return 0;
}
