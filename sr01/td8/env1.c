#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[],char **envp)
{
    char var[80], new[80];

    printf("Entrer la variable d'environement à traiter (en MAJUSCULES)\n");
    scanf("%s",var);

    char* res;
    res = getenv(var);
    if (res!=NULL) {
        printf ("Contenue de la variable : %s\n",res);
        strcpy(var,new);
        putenv(strcat(new,"=xxx"));
        res = getenv(var);
        printf ("Contenue de la variable : %s\n",res);
    } else printf("ERREUR");

    return 0;
}