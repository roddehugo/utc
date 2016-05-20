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
    dup(fd);
    printf("apres dup\n");
    close(fd);
    printf("Le 4eme printf...\n");
}
