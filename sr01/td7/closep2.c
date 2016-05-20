#include <stdio.h>
#include <fcntl.h>

main()
{
    int pid,i,status;
    int fd,fd2;

    fd=open("toto.txt",O_RDWR|O_CREAT,0666);
    printf( "avant close\n");
    /*On sauvegarde le rang du descripteur STDOUT dupliqué*/
    int rangstd = dup(1);
    printf("Rang STDOUT : %d\n",rangstd);
    close(1);
    printf("apres close\n");
    /*On sauvegarde le rang descripteur fd dupliqué = 1*/
    int rangfd = dup(fd);
    printf("Rang fd : %d\n",rangfd);
    printf("apres dup\n");
    /*On ferme le fichier fd*/
    close(fd);
    /*On ferme le rang dupliqué ci-dessus pour le libérer = 1*/
    close(rangfd);
    /*On remet le descripteur STDOUT dans le rang 1*/
    int new = dup(rangstd);
    printf("Rang : %d\n",new);
    printf("Le 4eme printf...\n");
}
