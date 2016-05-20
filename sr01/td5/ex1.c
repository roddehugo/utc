// Programme Calcul
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    float s=0;
    switch(argv[1][1]) {
    case 'a':
        printf("vous avez chosit de faire une addition :\n");
        for(i=2; i<argc; i++) {
            s += (float) atoi(argv[i]);
        }
        printf("somme = %f\n",s);
        break;
    case 'p':
        s=1;
        printf("vous avez chosit de faire un produit :\n");
        for(i=2; i<argc; i++) {
            s *= (float) atoi(argv[i]);
        }
        printf("produit = %f\n",s);
        break;
    case 'd':
        printf("vous avez chosit de faire une division :\n");
        s = (float) atoi(argv[2])/atoi(argv[3]);
        printf("division = %f\n",s);
        break;
    }
    return 0;
}