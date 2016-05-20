element(X,[X|_]).
element(X,[_|Q]):-element(X,Q).

/* Question 1 : Ecrire le prédicat succ(X,Y,G) qui s’efface si Y est le successeur de X dans le graphe G.*/ 
succ(X,Y,G):-element((X,Y),G).

/* Question 2 : Ecrire le prédicat degre(X,D,G) qui calcule le degré d’un sommet X dans le graphe G (i.e. le nombre d’arcs incidents en X). */
degre(X,D,[(X,_)|Q]):-!,degre(X,D2,Q), D is D2+1.
degre(X,D,[(_,X)|Q]):-!,degre(X,D2,Q), D is D2+1.
degre(X,D,[_|Q]):-!,degre(X,D,Q). /* le cut peut aussi être placé en fin */
degre(_,0,[]).
/* RESULT | ?- degre(2,X,[(1,2),(1,6),(2,3),(2,4),(3,4),(4,5)]).
X = 3 */ 

/* Question 3 : Ecrire le prédicat sommets(E,G) qui renvoie tous les sommets du graphe G dans une
liste E. Attention : il ne doit pas y avoir deux fois le même sommet dans E ...*/
sommets([X,Y|RESTE],[(X,Y)|Q]):-X\=Y,degre(X,O,Q),degre(Y,O,Q),sommets(RESTE,Q),!.
sommets([X|RESTE],[(X,_)|Q]):-degre(X,0,Q),sommets(RESTE,Q),!.
sommets([Y|RESTE],[(_,Y)|Q]):-degre(Y,0,Q),sommets(RESTE,Q),!.
sommets(RESTE,[_|Q]):-sommets(RESTE,Q),!.
sommets([],[]).
/* RESULT | ?- sommets(E,[(1,2),(1,6),(2,3),(2,4),(3,4),(4,5)]).
E = [1,6,2,3,2,3,4,5]*/

/* Question 4 :Ecrire le prédicat chemin(X,Y,G) qui vérifie qu’il existe un chemin pour aller d’un sommet X à un sommet Y dans le graphe G. */
chemin(X,Y,G):-succ(X,Y,G).
chemin(X,Y,G):-succ(X,Z,G),chemin(Z,Y,G).
/* RESULT | ?- | ?- chemin(1,5,[(1,2),(1,6),(2,3),(2,4),(3,4),(4,5)]).
true ?  */

/* Question 5 : Ecrire le prédicat chemin(X,Y,G,C) qui calcule le chemin C à parcourir pour aller d’un sommet X à un sommet Y dans le graphe G. */
chemin(X,Y,G,[X|Y]):-succ(X,Y,G).
chemin(X,Y,G,[X|RESTE]):-succ(X,Z,G),chemin(Z,Y,G,RESTE).
/* RESULT  chemin(1,7,[(1,2),(1,6),(2,3),(2,4),(3,4),(4,5),(7,2),(3,7),(2,0),(5,3)],C).
C = [1,2,3|7] ?  */

/* Question 4 */ 
remove(ARC,[ARC|Q],Q):-!.
remove(ARC,[Z|Q],[Z,RES]):-remove(ARC,Q,RES).
chemin(X,Y,G):-succ(X,Y,G).
chemin(X,Y,G):-succ(X,Z,G),remove((X,Z),G,G2),chemin(Z,Y,G2).

/* Question 5 */
chemin(X,Y,G,[X|Y]):-succ(X,Y,G).
chemin(X,Y,G,[X|RESTE]):-succ(X,Z,G),remove((X,Z),G,G2),chemin(Z,Y,G2,RESTE).

/* Question 6 */
circuit(G):-chemin(X,X,G),!. 

/* Question 7 */
elementaire([]).
elementaire([X|Q]):-\+element(X,Q),elementaire(Q). /* Problème avec le signe +  */

/* Graphe valué : [(1,2,1),(1,6,0),(2,3,6),(2,4,5),(3,4,2),(4,5,1),(7,2,4),(3,7,1),(2,0,0),(5,3,2)]*/

/* Question 8 */
chemin(X,Y,G,[X,Y],V):-succ(X,Y,V,G).
succ(X,Y,V,G):-element((X,Y,V),G).
chemin(X,Y,(T,[X|RESTE],V):-succ(X,Z,VXZ,G),remove((X,Z,VXZ),G,G2),chemin(Z,Y,G2,RESTE,VZY),V is VXZ+VZY.

/* Question 9 */
un_plus_court(X,Y,G,V):-chemin(X,Y,G,_,NV),NV<V.
pcc(X,Y,G,C,V):-chemin(X,Y,G,C,V),\+un_plus_court(X,Y,G,V).