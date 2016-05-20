#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t   pid1,pid2;
    pid1 = fork();

    if (pid1 > 0) {
        /* Processus père      */
        printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid1);
        pid2 = fork();
        if (pid2 > 0) {
            /* Processus père      */
            printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid2);
        } else if (pid2 == 0) {
            /* Processus fils  2    */
            printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
        } else {
            /* Traitement d'erreur */
            printf("ERREUR\n");
        }

    } else if (pid1 == 0) {
        /* Processus fils 1     */
        printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
    } else {
        /* Traitement d'erreur */
        printf("ERREUR\n");
    }

    return 0;
}