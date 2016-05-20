#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*Commentaires dans le fichier .txt joint*/

int recu=0;
int a,b;

void captint(int sig)
{
    printf ("capte signal %d recu=%d\n",sig,recu);
    recu++;
    usleep(a);
}

void main(int argc, char *argv[])
{
    int i=0,n=0;
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    signal(SIGINT,captint);
    printf("capter ctrl-C\n");
    i = fork();
    if (i==-1) {
        printf("echec fork\n");
        exit(0);
    }
    if (i==0) { /* fils */
        while (n<100) {
            usleep(b);
            printf("boucle envoi SIGINT n=%d\n",n);
            kill(getppid(), SIGINT);
            n++;
        }
    } else { /* pere */
        signal(SIGINT, captint);
        while(1) pause;
    }/* fin if else */

}/* fin main */