#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int attente;
int sigpere;
int sigfils;

void captpere (int signum)
{
    printf("SIGINT PERE restait %d sec.\n",attente);
    if(sigpere==3)
        exit(0);
    sigpere++;
}

void captfils (int signum)
{
    printf("SIGINT FILS\n");
    rectvert(2);
    if(sigfils==3) {
        detruitrec();
        exit(0);
    }
    sigfils++;
}


void main()
{
    attente=10;
    sigpere=0;
    sigfils=0;

    printf("Père : %d\n", getpid());
    int pid = fork();

    if (pid==-1) {
        printf("echec fork\n");
        exit(0);
    } else if (pid==0) { /* fils */
        int i;
        signal(SIGINT,captfils);
        initrec();
        while(i!=-1) {
            i=attendreclic();
            printf("Clic capté %d\n",i);
            if(i==0) {
                printf("Envoi du SIGINT au père : %d\n", getppid());
                kill(getppid(), SIGINT);
            }
        }
    } else { /* pere */
        signal(SIGINT,captpere);
        while(attente>0) {
            attente = sleep(attente);
        }
    }/* fin if else */

    printf("fin\n");
}