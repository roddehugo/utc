#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/*Commentaires dans le fichier .txt joint*/

void routinesigint (int signum)
{
    printf("je suis dans SIGINT\n");
    sleep(5);
}

void routinesigquit (int signum)
{
    printf("je suis dans SIGQUIT\n");
    sleep(5);
}

main()
{
    printf("%d\n", getpid());
    signal(SIGINT,routinesigint);
    signal(SIGQUIT,routinesigquit);
    while(1) pause();

}