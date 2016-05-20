#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int attente;
int sigpere;
int sigfils;
int lespid[3];

void captpere (int signum)
{
    printf("SIGINT PERE");
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
    attente=5;
    sigpere=0;
    sigfils=0;

    printf("Père : %d\n", getpid());
    lespid[0]=getpid();
    int pid = fork();

    if (pid==-1) {
        printf("echec fork\n");
        exit(0);
    } else if (pid==0) { /* fils */
        int i;
        lespid[1]=getpid();
        int pid2 = fork();
        if (pid2==-1) {
            printf("echec fork\n");
            exit(0);
        } else { /* fils */
            int i;
            lespid[2]=getpid();
            signal(SIGINT,captfils);
            initrec();
            while(i!=-1) {
                i=attendreclic();
                printf("Clic capté %d\n",i);
                if ((i==0) || (i==1) || (i==2)) {
                    printf("Envoi du SIGINT au pid n°%d : %d\n",i,lespid[i]);
                    kill(lespid[i], SIGINT);
                } else if (i==3) {
                    printf("Envoi du SIGINT aux 3 : %d %d %d \n",lespid[0], lespid[1], lespid[2]);
                    kill(lespid[0], SIGINT);
                    kill(lespid[1], SIGINT);
                    kill(lespid[2], SIGINT);
                }
            }
        }
    } else { /* pere */
        signal(SIGINT,captpere);
        while(1) {
            sleep(attente);
        }
    }/* fin if else */

    printf("fin\n");
}