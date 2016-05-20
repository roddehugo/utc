#include <stdio.h>
#include <unistd.h>

int main()
{

    pid_t   pid;
    pid = fork ();
    if (pid > 0) {
        /* Processus père      */
        printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid);
    } else if (pid == 0) {
        /* Processus fils      */
        printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
    } else {
        /* Traitement d'erreur */
        printf("ERREUR\n");
    }
    return 0;
}