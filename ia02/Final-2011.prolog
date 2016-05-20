
longueur([_|Q], L) :- longueur(Q,N), L is N+1.

get_nb_lignes(G,NBL) :- longueur(G,NBL).

get_nb_colonnes([], 0).
get_nb_colonnes([T|_], NBC) :- longueur(T,NBC).

element_n(1, [T|_], T) :- !.
element_n(N, [_|Q], X) :- N2 is N-1, N2 > 0, element_n(N2,Q,X).

ligne_n(N,G,L) :- element_n(N,G,L).

gec(L1,_,_,0,L1) :- !.
gec(L1,G,N,NBL,[E|L2]) :- NBL2 is NBL-1, gec(L1,G,N,NBL2,L2), element_n(NBL,G,L), element_n(N,L,E).

colonne_n(N,G,C) :- get_nb_lignes(G,NBL), gec([], G, N, NBL, C).

nombre(_,[],0) :- !.
nombre(X,[X|Q],N) :- !, nombre(X,Q,N2), N is N2+1.
nombre(X,[_|Q],N) :- !, nombre(X,Q,N).

vecteur_solution(Vect,NB_C, NB_L) :- nombre(g,Vect,NB_C), nombre(n, Vect, NB_L).

verif_ligne(0,_,_) :- !.
verif_ligne(N,G,C) :- element_n(N,C,(C1,C2)), ligne_n(N,G,L), vecteur_solution(L,C1,C2), N2 is N-1, verif_ligne(N2,G,C).

lignes_grille_solution(Grille,Cont_L) :- get_nb_lignes(Grille,NBL), verif_ligne(NBL, Grille, Cont_L).

verif_colonne(0,_,_) :- !.
verif_colonne(N,G,C) :- element_n(N,C,(C1,C2)), colonne_n(N,G,L), vecteur_solution(L,C1,C2), N2 is N-1, verif_colonne(N2,G,C).

colonnes_grille_solution(Grille, Cont_C) :- get_nb_colonnes(Grille, NBC), verif_colonne(NBC, Grille, Cont_C).

grille_solution(Grille,Cont_L, Cont_C) :- lignes_grille_solution(Grille, Cont_L), colonnes_grille_solution(Grille, Cont_C).

placer_1_couleur(C,[0|Q],[C|Q],1).
placer_1_couleur(C,[T|Q], NewVect, Pos) :- placer_1_couleur(C,Q,Q2,Pos2), Pos is Pos2+1, NewVect = [T|Q2].

placer_1_couleur_a_partir(C,I,Vect,NewVect, Pos) :- placer_1_couleur(C,Vect,NewVect,Pos), Pos >= I.

placer_nb_couleurs(C,NB,Vect,NewVect) :- placer_nb_couleurs_a_partir(C,NB,0,Vect,NewVect).

placer_nb_couleurs_a_partir(_,0,_,V,V).
placer_nb_couleurs_a_partir(C,NB,I,V,NV) :- placer_1_couleur_a_partir(C,I,V,NV2,Pos),
                                           NB2 is NB-1, I2 is Pos+1,
                                           placer_nb_couleurs_a_partir(C,NB2,I2,NV2,NV).

placer_gris_et_noirs(NB_G,NB_N,Vect,NewVect) :- placer_nb_couleurs(g,NB_G,Vect,NV1), placer_nb_couleurs(n,NB_N,NV1,NewVect).

genere_ligne_blanche(N,[]) :- N < 1, !.
genere_ligne_blanche(1,[0]).
genere_ligne_blanche(N,[0|L]) :- N2 is N-1, genere_ligne_blanche(N2,L), !.

genere_ligne(N,Ligne,NB_G,NB_N) :- genere_ligne_blanche(N,L), placer_nb_couleurs(g,NB_G,L,L2), placer_nb_couleurs(n,NB_N,L2,Ligne).

genere_grille(Grille,Cont_L,Cont_C) :- get_nb_lignes(Cont_L, N), get_nb_lignes(Cont_C,M),
                                       genere_lignes(M, Grille, Cont_L, N, 1),
                                       grille_solution(Grille,Cont_L,Cont_C). 

genere_lignes(_,[],_,0, _) :- !.
genere_lignes(N,[G2|G3],Cont_L, NB, I) :- NB2 is NB-1,  I2 is I+1, element_n(I,Cont_L,(NB_G,NB_N)),
                                          genere_ligne(N, G2, NB_G,NB_N), genere_lignes(N,G3,Cont_L,NB2, I2).
