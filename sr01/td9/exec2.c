#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void my_system(char *path, char **argv)
{
    printf("Execution de la commande :\n");
    execv(path, argv);
}

int main()
{
    char path[80] = "/bin/ls";
    char *argv[] = {"ls", "-l", "-a", NULL};
    my_system(path,argv);

    char *argv2[] = {"ls", "*.c", NULL};
    my_system(path,argv2);
}