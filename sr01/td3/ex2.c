#include <stdio.h>

int main()
{
    int rep,date,res;
    char *jour[7]= {"lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche"};
    do {
        printf("Donnez l'indice du premier jour du mois:(lundi=0...dimanche=6)\n");
        scanf("%d",&rep);
    } while (rep<0 || rep>7);
    do {
        printf("Donnez la date:\n");
        scanf("%d",&date);
    } while (date<1 || rep>31);

    res = date%7+rep-1;

    if (res>=7)
        res-=7;
    printf("Le %d est un %s.\n",date,jour[res]);
    return 0;
}