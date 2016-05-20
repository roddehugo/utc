#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
int main()
{

    pid_t   pid;
    pid = fork ();
    if (pid > 0) {
        /* Processus père      */
        printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid);
        int signal = wait(NULL);
        printf("Signal exit fils : %d\n",signal);
    } else if (pid == 0) {
        /* Processus fils      */
        printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
        exit(EXIT_SUCCESS);
    } else {
        /* Traitement d'erreur */
        printf("ERREUR\n");
    }
    return 0;
}