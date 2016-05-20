#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*Commentaires dans le fichier .txt joint*/

int recu=0;

void captint(int sig)
{
    printf ("capte signal %d recu=%d\n",sig,recu);
    recu++;
}

void main(int argc, char *argv[])
{
    int i=0,n=0;
    signal(SIGINT,captint);
    printf("capter ctrl-C\n");
    i = fork();
    if (i==-1) {
        printf("echec fork\n");
        exit(0);
    }
    if (i==0) { /* fils */
        sleep(1);
        while (n<3) {
            kill(getppid(), SIGINT);
            n++;
            sleep(1);
        }
    } else { /* pere */
        wait();
        signal(SIGINT, captint);
        while (errno==EINTR) n=wait();
    }/* fin if else */

}/* fin main */