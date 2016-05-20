/** exemple_waitpid_1 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main (void)
{
    pid_t	pid1, pid2;
    int	status;

    switch (pid1 = fork()) {
    case -1 :
        printf("Erreur dans fork()\n");
        exit(EXIT_FAILURE);
    case 0 : /* fils 1 */
        printf("Fils 1 : PID = %d\n", getpid());
        sleep(2);
        exit(1);

    default : /* père */
        switch (pid2=fork()) {
        case -1 :
            printf("Erreur dans fork()\n");
            exit(EXIT_FAILURE);
        case 0 : /* fils 2 */
            printf("Fils 2 : PID = %d\n",getpid());
            sleep(1);
            exit(2);
        default : /* père */
            if ((waitpid(pid1, & status, 0)> 0) && (WIFEXITED(status)) ) {
                printf("PERE: fils%d terminé par exit (%d)\n",pid1, WEXITSTATUS(status));
            }
            return EXIT_SUCCESS;
            break;
        }


        break;
    }
}


