#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
int main(int argc, char *argv[],char **envp)
{
    int i;
    for(i=0; environ[i] ; i++) {
        printf("Envp[%d] : %s \n",i,environ[i]);
    }
    printf("Il y a %d variables d’environnement : \n",i);
    return 0;
}