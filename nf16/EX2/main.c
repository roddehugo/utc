#include <stdio.h>

int f(int n)
{
    int a,i,j,sn;
    a=1;
    sn=a;
    for (i=1; i<=n; i++) {
        a=1;
        for (j=1; j<=i; j++) {
            a*=2;
        }
        sn+=a;
    }
    return sn;
}

int main(int argc, const char * argv[])
{

    printf("%d\n",f(3));
    return 0;
}
