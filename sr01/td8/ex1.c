#include <stdio.h>

int main()
{

    printf("Bonjour voilà mon numéro de processus (attribué à ce programme) : %d \n",getpid());
    printf("Et voilà celui de mon père (qui m'exécute donc celui de ce terminal) : %d \n",getppid());
    printf("Celui du user : %d\n",getuid());
    printf("Celui du groupe du user :%d\n",getgid());

    return 0;
}