#include "main.h"

//contruire un polynome
Monome * monome_constructeur (int c, int d)
{
    Monome * M = malloc(sizeof(Monome)); // !!!!
    M->c=c;
    M->d=d;
    M->suivant = NULL;
    return M;
}

// ---------- CONSTRUCTEUR ----------
Polynome polynome_constructeur(int c, int d, Polynome P)
{
    Polynome Q = (Polynome)malloc(sizeof(Monome));
    Q->c=c;
    Q->d=d;
    Q->suivant=P;
    return Q;
}

// ---------- DEGRE ----------
//degr� it�ratif
int degre_ite (Polynome P)
{
    // /!\ 'utilisation de Tmp pour ne pas modifier P ds le main" FAUX, lorsque l'on travaille sur un pointeur,
    //la valeur du pointeur N'EST PAS MODIFIEE dans la fonction principale,
    //c'est la valeur point�e pra le pointeur qui est modifi�e...
    //Polynome Tmp=P; //intutile...
    int deg_max = -1; //prend en compte le cas o� P est null
    while(P!=NULL) {
        if (P->d > deg_max) deg_max=P->d;
        P=P->suivant;
    }
    return deg_max;
}
//degr� r�cursif
int degre_rec(Polynome P)
{
    if (P==NULL) return -1;
    else {
        int d_max = degre_rec(P->suivant);
        if (P->d > d_max) return P->d;
        else return d_max;
    }
}

// ---------- AFFICHAGE ----------
void print_monome (Monome * PM)
{
    if(PM->c != 0) { //inutile, normalement ce cas ne devrait pas arriver
        if(PM->d==0) printf("%d",PM->c);
        else if (PM->d==1) printf("%dx",PM->c);
        else printf("%dx^%d",PM->c,PM->d);
    }
}
//affichage it�ratif
void print_polynome_ite(Polynome P)
{
    while(P!=NULL) {
        //affichage du monome
        print_monome(P);
        //affichage du s�parateur si besoin
        if (P->suivant!=NULL) printf(" + ");
        //passage au monome suivant
        P=P->suivant;
    }
    printf("\n");
}
//affichage r�cursif
void print_polynome_rec(Polynome P)
{
    if (P!=NULL) {
        print_monome(P);
        if (P->suivant!=NULL) printf(" + ");
        else printf("\n");
        print_polynome_rec(P->suivant);
    }
}


// ---------- ADDITION ----------
//m�me principe que l'exercice 1 diff�rence sym�trique
//addition r�cursive
Polynome add_polynome_rec(Polynome P1, Polynome P2)
{
    if (P1==NULL && P2==NULL) return NULL;
    else if (P1==NULL) return P2;
    else if (P2==NULL) return P1;
    else {
        //si P1 et P2 sont de m�me degr�
        if (P1->d == P2->d) {
            //si la somme des coef est nulle, on passe aux monomes suivants dans P1 et P2
            if ((P1->c + P2->c) == 0) return add_polynome_rec(P1->suivant,P2->suivant);
            //sinon on construit un nouveau polynome ayant pr coef la somme des coef de P1 et P2
            //et pour �l�ment suivant la somme du reste de P1 et du reste de P2 //ici l'alloc dynamique est faite grace � la fct poly_const
            else return polynome_constructeur(P1->c+P2->c,P1->d,add_polynome_rec(P1->suivant,P2->suivant));
        }
        //degr� de P1 > degr� de P2, il faut
        // - ajouter P2 en t�te EN CONSTRUISANT UN NOUVEAU POKYNOME sinon on �crase P1 et P2
        // - passer � l'�l�ment suivant dans P2
        // - effecteur le reste de l'addition de P1 et P2
        //NE PAS FAIRE
        //P2->suivant = add_polynome(P1,P2->suivant); return P2; car on modifie P2...
        else if (P1->d > P2->d) return polynome_constructeur(P2->c,P2->d,add_polynome_rec(P1,P2->suivant));
        // cas sym�trique avec P1
        else return polynome_constructeur(P1->c,P1->d,add_polynome_rec(P1->suivant,P2));
    }
}
//pour l'addition it�rative, m�me principe que la diff�rence sym mais compliqu� !
Polynome add_polynome_ite(Polynome P1, Polynome P2)
{
    Polynome Result = malloc(sizeof(Monome));
    Result = NULL; //!! Ne JAMAIS utiliser directement le Monome, cr�er une copine !!
    //initialiser Produit
    if (P1!=NULL && P2!=NULL) {
        if(P1->d < P2->d) {
            Result = polynome_constructeur(P1->c,P1->d,NULL);
            P1=P1->suivant;
        } else if (P1->d > P2->d) {
            Result =  polynome_constructeur(P2->c,P2->d,NULL);
            P2=P2->suivant;
        } else { //p& et p2 de m�me degr�
            Result =  polynome_constructeur(P1->c+P2->c,P1->d,NULL);
            P1=P1->suivant;
            P2=P2->suivant;
        }
    } else if(P1!=NULL) { //P2=NULL, renvoyer P1 et sortir de la fonction
        return P1;
    } else if(P2!=NULL) { //P1 NULL, renvoyer P2 et sortir de la fonction
        return P2;
    } else return NULL;
    //utilisation d'une variable temporaire pr construire la liste chainee :
    Polynome Tmp=Result;
    //construire la chaine ordonn�e
    while(P1!=NULL && P2!=NULL) {
        if(P1->d < P2->d) {
            //on ajoute le nouveau monome en fin de liste
            Tmp->suivant=polynome_constructeur(P1->c,P1->d,NULL);
            P1=P1->suivant;
        } else if (P1->d > P2->d) {
            Tmp->suivant= polynome_constructeur(P2->c,P2->d,NULL);
            P2=P2->suivant;
        } else {
            Tmp->suivant=polynome_constructeur(P1->c+P2->c,P1->d,NULL);
            P1=P1->suivant;
            P2=P2->suivant;
        }
        Tmp=Tmp->suivant;
    }
    //quand l'un des deux poly est vide, recopier l'autre
    if(P1!=NULL) {
        Tmp->suivant= P1;
    } else if(P2!=NULL) {
        Tmp->suivant=P2;
    }
    return Result;
}






// ---------- MULTIPLICATION ----------
//produit d'un polynome par un monome --
Polynome produit_polynome_monome (int c, int d, Polynome P)
{
    if(P==NULL) return NULL;
    //pour le premier �l�ment de P :
    //produit = (c * P->c) x ^ (d + P->d) //la relation d'ordre sur les degr�s est bien conserv�e
    //multiplier les �l�ments suivants
    else return polynome_constructeur(c*P->c,d+P->d,produit_polynome_monome(c,d,P->suivant));
}
//produit de deux polynomes :
//on  multiplie chaque �l�ment de P1 par P2 (fonction produit_ploynome_monome) et on additionne tout
//produit de deux polynomes -- fonction it�rative
Polynome produit_polynomes_ite(Polynome P1, Polynome P2)
{
    Polynome Result=NULL;
    while(P1!=NULL) {
        Polynome ProdPolynomeMonome = produit_polynome_monome(P1->c,P1->d,P2);
        Result = add_polynome_rec(ProdPolynomeMonome,Result);
        P1=P1->suivant;
    }
    return Result;
}
//produit de deux polynomes -- fonction r�cursive
Polynome produit_polynomes_rec(Polynome P1, Polynome P2)
{
    if (P1==NULL) return NULL;
    else return add_polynome_rec(
                        produit_polynome_monome(P1->c,P1->d,P2),
                        produit_polynomes_rec(P1->suivant,P2)
                    );
}
