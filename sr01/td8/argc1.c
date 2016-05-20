#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char **envp)
{
    int i;
    for(i=0; envp[i] ; i++) {
        printf("Envp[%d] : %s \n",i,envp[i]);
    }
    printf("Il y a %d variables d’environnement : \n",i);
    return 0;
}