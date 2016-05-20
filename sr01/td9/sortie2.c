#include <stdio.h>
#include <stdlib.h>

void fonc()
{
    printf("La fonction fonc() a bien été lancée !\n");
}

int main()
{
    atexit(fonc);
    if (0) {
        printf("Sortie avec ERREUR\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Sortie avec SUCCES\n");
        exit(EXIT_SUCCESS);
    }
}

/*La fonction atexit() enregistre la fonction donnée pour que celle-ci soit
automatiquement invoquée lorsque le processus se termine normalement avec
exit() ou par un retour de la fonction main().
Les fonctions ainsi enregistrées sont invoquées en ordre inverse de leur
enregistrement, aucun argument n'est transmis.*/