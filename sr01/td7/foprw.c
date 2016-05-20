#include <stdio.h>

int main()
{
    FILE * fa,* fb;
    char buf[1];
    int n;
    fa = fopen("fop.in","r+");
    fb = fopen("fop.out","w");

    if (fa==NULL || fb==NULL) {
        perror("fop erreur :");
        return 0;
    }

    while(!feof(fa)) {
        n = fread(buf,1,1,fa);
        while(buf[0] != '\n') {
            if(n>0)
                fwrite(buf,1,1,fb);
            n = fread(buf,1,1,fa);
        }
        if(n>0)
            fwrite("xxx\n",1,4,fb);
    }

    fclose(fa);
    fclose(fb);

    return 0;
}
