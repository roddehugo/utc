#include <stdio.h>

typedef struct noeud {
    int cle;
    struct noeud *gch;
    struct noeud *dte;
    struct noeud *pere;
}*ABR;

ABR rotation_droite(ABR x)
{
    if(x==NULL) return NULL;

    ABR y = x->gch;
    ABR c = x->dte;
    ABR x_pere = x->pere;
    //C devient le fils gauche de x
    x->gch = c;
    c->pere = x;

    //x devient fils droit de y
    y->dte = x;
    x->pere = y;

    //l'ancien pere de x devient le pere de y
    y->pere = x_pere;
    if(x==x_pere->gch)
        x_pere->gch=y;
    else if(x==x_pere->dte)
        x_pere->dte=y;
    return y;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

