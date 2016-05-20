#include <stdio.h>
#include <stdlib.h>
int main( )
{
    int a[5], i, *p;
    a[0] = 1;
    p = a;
    for (i = 0; i < 4; i++) {
        *(p + a[i]) = *(a + i) + 1;
        *(p + a[i] - 1) = *(a + i + 1) + 2;
    }
    i++;
    printf ("%d\n", i++/2 + *p);
    for (i = 0; i < 5; i++)
        printf ("%d ", a[i]);
    printf ("\n");
    exit (0);
}
