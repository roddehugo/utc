/* fop.c -- démo fopen fread ... */
#include <stdio.h>

int main()
{
    FILE * fa;
    char buf[80];
    int n;
    fa = fopen("fop.txt","a+");
    if (fa==NULL) {
        perror("fop erreur :");
        return 0;
    }
    n = fread(buf,1,80,fa);
    if (n!=80) {
        perror("read");
    }
    buf[n]='\0';
    printf("lu n=%d =>%s\n",n,buf);
    n = fwrite("xxx yyy\n",1,8,fa);
    if (n!=8) {
        perror("write");
    }
    fclose(fa);
}
