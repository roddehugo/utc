/* 1- tete(T,L) qui vérifie si T est la valeur de la tête.*/
tete(T,L):-[T|_]=L.
teteBis(T,[T|_]).

/* queue(Q,L) qui vérifie si T est la valeur de la queue. */
queue(Q,[_|Q]).

/* imprime(L) qui affiche le contenu de la liste L. */
imprime([T|Q]):-write(T),nl,imprime(Q).
imprime([]).

/* element(X,L) vérifie si X est présent dans la liste L. */
element(X,[X|_]).
element(X,[_|Q]):-element(X,Q).
/* RESULT element(3,[4,5,3,6]). ou element(X,[4,5,3,6]). */

/* verifie si X est le dernier élément de la liste*/
dernier(T,[T|[]]).
dernier(X,[_|Q]):-dernier(X,Q).

/* longueur*/
longueur(0,[]).
longueur(N,[_|Q]):-longueur(M,Q),N is M+1.

/* nombre de fois ou X apparait dans la liste*/
nombre(_,[], 0).
nombre(X, [X|Q], NB):-nombre(X,Q,NBIS), NBIS is NB+1,!.
nombre(X,[_|Q],NB):-nombre(X,Q,NB).

/* concat*/
concat([],L,L).
concat([T|Q],L,[T|R]):-concat(Q,L,R).

/* inverse */
inverse([],[]).
inverse([T|Q],R):-inverse(Q,QR),concat(QR,[T],R).

/* inverse 2e méthode */
reverse([],L,L).
reverse([T|Q],Tmp,Res):-reverse(Q,[T|Tmp],Res).
reverse(L,LI):-reverse(L,[],LI).

/* Tri */
partionner(_,[],[],[]).
partionner(X,[T|Q],[T|L1],L2):-T=<X,partition(X,Q,L1,L2).
partionner(X,[T|Q],L1,[T|L2]):-T>X,partition(X,Q,L1,L2).

tri([],[]).
tri([T|Q],LT):-partionner(T,Q,L1,L2),tri(L1,L1T),tri(L2,L2T),concat(L1T,[T|L2T],LT).
