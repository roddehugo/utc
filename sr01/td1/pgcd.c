/* pgcd.c calcul du pgcd de 2 nombres:*/

#include <stdio.h>

int pgcd(int x, int y)
{

    int reste;

    do {

        reste= x % y;

        if (reste == 0) break;

        x = y;

        y = reste;

    } while (1);
    return (y);

}

int main ()
{

    int a, b;

    printf("\n donner a et b ->: ");

    scanf("%d %d", &a, &b);



    if (b>a) {

        int c = a;

        a = b;

        b = c;
    }



    printf(" Leur PGCD est : %d\n\n", pgcd(a,b));

}

