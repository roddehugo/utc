#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void my_system(char *path, char **argv)
{
    printf("Execution de la commande :\n");
    if(execv(path, argv) == -1)
        printf("%s\n",strerror(errno));
}

int main()
{
    pid_t pid1,pid2;
    pid1 = fork();
    int status;

    if (pid1 > 0) {
        //PERE
        int signal = wait(NULL);
        printf("Signal exit fils : %d\n",signal);
        pid2=fork();
        if(pid2>0) {
            //PERE
            int signal = wait(NULL);
            printf("Signal exit fils : %d\n",signal);
        } else if(pid2==0) {
            char path[80] = "/bin/ls *.c";
            system(path);
        } else {
            /* Traitement d'erreur */
            printf("ERREUR\n");
        }
    } else if(pid1==0) {
        //FILS
        char path[80] = "/bin/ls";
        char *argv[] = {"ls", "-l", "-a", NULL};
        my_system(path,argv);
    } else {
        /* Traitement d'erreur */
        printf("ERREUR\n");
    }

}