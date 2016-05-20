#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int fibo1(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else {
        return fibo1(n-1)+fibo1(n-2);
    }
}

int fibo2(int n)
{

    if (n==0)
        return 0;
    else if(n==1)
        return 1;
    else {
        if(n%2==0)
            return fibo2(pow(n/2,2))+2*fibo2(n/2)*fibo2((n/2)-1);
        else
            return fibo2(pow((n-1)/2,2))+pow(fibo2(((n-1)/2)+1),2);
    }
}
int main(int argc, char const *argv[])
{
    clock_t start1, end1;
    start1 = clock();
    printf("Resultat : %d\n", fibo1(4));
    end1=clock();
    printf("Fibo 1 : %f:\n", ((double)end1-start1) / CLOCKS_PER_SEC);

    clock_t start2, end2;
    start2 = clock();
    printf("Resultat : %d\n", fibo2(3));
    end2=clock();
    printf("Fibo 2 : %f:\n", ((double)end2-start2) / CLOCKS_PER_SEC);
    return 0;
}
