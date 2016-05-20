#include <stdlib.h>
#include <stdio.h>

int main()
{
    system("/bin/ls -la");
    printf("--------\n");
    system("/bin/ls *.c");
    return 0;
}