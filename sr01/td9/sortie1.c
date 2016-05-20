#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (1) {
        printf("Sortie avec ERREUR\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Sortie avec SUCCES\n");
        exit(EXIT_SUCCESS);
    }
}

/*Utilisation des exit() qui nécessitent la bibliothèque stdlib.h
et un paramètre*/
