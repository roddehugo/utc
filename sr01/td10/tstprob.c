#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

int probe(int *a)
{
    int n = setjmp(env);
    if(n==0) {
        printf("Val %d\n",*a);
        return 1;
    } else {
        return 0;
    }

}


void handler (int signum)
{
    printf("signal SIGSEV\n");
    longjmp(env,1);
}

void main()
{
    int tab[1000];
    int i,*ia1,index = 0;
    signal(SIGSEGV,handler);
    while(1) {
        ia1 = &tab[index];
        i = probe(ia1);
        if (i==0) {
            printf("\nprobe fail at index=%d ia1=%x\n",index,ia1);
            break;
        }
        index++;
    }
}