#include <stdio.h>
#include <fcntl.h>

main()
{
    int pid,i,status;
    int fd,fd2;

    fd=open("toto.txt",O_RDWR|O_CREAT,0666);
    printf( "avant close\n");
    close(1);
    printf("apres close\n");

    int rangfd = dup(fd);
    printf("Rang fd : %d\n",rangfd);
    printf("apres dup\n");
    close(fd);
    close(rangfd);

    /*On ouvre le fichier correspondant à l'écran*/
    int new = open("/dev/tty", O_WRONLY);
    printf("Rang : %d\n",new);
    printf("Le 4eme printf...\n");
}
