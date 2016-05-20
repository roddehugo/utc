#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t   pid1,pid2;
    pid1 = fork();
    int status;

    if (pid1 > 0) {
        /* Processus père      */
        printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid1);
        waitpid(pid1,&status,0);
        printf("Signal exit fils : %d\n",WIFEXITED(status) );
        pid2 = fork();
        if (pid2 > 0) {
            /* Processus père      */
            printf("Ici le parent, mon pid est %d, le pid de mon fils est %d\n",getpid(),pid2);
            waitpid(pid2,&status,0);
            printf("Signal exit fils : %d\n",WIFEXITED(status) );
        } else if (pid2 == 0) {
            /* Processus fils  2    */
            printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
            exit(0);
        } else {
            /* Traitement d'erreur */
            printf("ERREUR\n");
        }

    } else if (pid1 == 0) {
        /* Processus fils 1     */
        printf("Ici le fils, mon pid est %d, le pid de mon père est %d\n",getpid(),getppid());
        exit(0);
    } else {
        /* Traitement d'erreur */
        printf("ERREUR\n");
    }

    return 0;
}