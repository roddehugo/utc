/** exemple_wait_1.c **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void affichage_type_de_terminaison (pid_t pid, int status);

int processus_fils (int numero);

int
main (void)
{
    pid_t	pid;
    int	status;
    int	numero_fils;

    for (numero_fils = 0; numero_fils < 4; numero_fils ++) {

        switch (fork()) {
        case -1 :
            printf("Erreur dans fork()\n");
            exit(EXIT_FAILURE);
        case 0 :
            printf("Fils %d : PID = %d\n",
                   numero_fils, getpid());
            return processus_fils(numero_fils);
        default :
            /* processus père */
            break;
        }
    }

    /* ici il n'y a plus que le processus pere*/
    while ((pid = wait(& status)) > 0)
        affichage_type_de_terminaison(pid, status);
    return EXIT_SUCCESS;
}

void affichage_type_de_terminaison (pid_t pid, int status)
{
    printf("Le processus %d ", pid);
    if (WIFEXITED(status)) {
        printf ("s'est terminé normalement avec le code %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf ("s'est terminé à cause du signal %d (%s)\n",WTERMSIG(status), sys_siglist[WTERMSIG(status)]);

    } else if (WIFSTOPPED(status)) {
        printf("s'est arrêté à cause du signal %d (%s)\n",WSTOPSIG(status),
               sys_siglist[WSTOPSIG(status)]);
    }
}

int processus_fils (int numero)
{
    switch (numero) {

    case 0 :
        return 1;
    case 1 :
        exit(2);
    case 2 :
        abort();
    case 3 :
        raise(SIGUSR1);
    }
    return numero;
}
