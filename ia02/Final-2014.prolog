%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%% Partie I %%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%% Ajoute X à la fin d'une liste
append([],X,X).                            
append([X|Y],Z,[X|W]):- append(Y,Z,W).

%% Concatène 2 listes
concat([],L,L).
concat([T|Q],L,[T|R]):-concat(Q,L,R).

%% S'efface si X appartient à la liste
element(X,[X|_]).
element(X,[_|Q]):- element(X,Q).

%% Valeur absolue de X unifiée avec AX
abs(X,AX):- X<0, AX is -X,!.
abs(X,AX):- AX is X.

%% Générer une liste de Min à Max, unifie le résultat avec Result
genere(X, X, [X]):- !.
genere(Min, Max, [Min|Result]):- Min =< Max, Min1 is Min+1, genere(Min1, Max, Result).

%% Unifie le résultat dans R de tous les éléments =< à X
retire_el(_,[],[]).
retire_el(X,[T|Q],[T|R]):- T =< X, retire_el(X,Q,R),!.
retire_el(X,[_|Q],R):- retire_el(X,Q,R).

%% S'efface si tous les éléments de L sont différents 2 à 2
alldiff(_,[]).
alldiff(X,[T|Q]):- X\=T, alldiff(X,Q).
%% Prédicat à 1 argument qui boucle sur le reste de la liste
alldiff([]).
alldiff([T1|Q]):- alldiff(T1,Q), alldiff(Q).

%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%% Partie II %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%% Inverse de retire_el
retire_el_inf(_,[],[]).
retire_el_inf(X,[T|Q],[T|R]):- T > X, retire_el_inf(X,Q,R),!.
retire_el_inf(X,[_|Q],R):- retire_el_inf(X,Q,R).

%% Choisir N marques parmi les éléments de la liste L des marques possibles
choisirNmarques(0,_,[]).
choisirNmarques(N,L,[X|S]):- element(X,L), retire_el_inf(X,L,L1), N1 is N-1, choisirNmarques(N1,L1,S). 

%% Calcul dans I la liste de tous les intervalles entre une marque M et une liste de marques L
faireIntervalles(_,[],[]).
faireIntervalles(X,[T|Q],[R|S]):- L is X-T, abs(L,R), faireIntervalles(X,Q,S).

%% Calcul dans I tous les intervalles
intervalles([],[]).
intervalles([T|Q],NewI):- faireIntervalles(T,Q,I), intervalles(Q,I2), concat(I,I2,NewI).

%% Choisit N marques entre 0 et UB de telle façon que Regle désigne les N marques d'une règle de Golomb
golombUB(N,Regle,UB):- genere(0,UB,L), choisirNmarques(N,L,Regle), alldiff(Regle).

%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%% Partie II %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%% Unifie avec L la longueur métrique (dernier élément) de la Regle
longueur([T|[]],T).
longueur([_|Q],L):- longueur(Q,L).

%% Unifie la Regle de Golomb de N marques la plus courte et de longueur L
meilleurRegle(N,Regle,L):- golombUB(N,R,L),longueur(R,L), longueur(Regle,Lr), L < Lr.

%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%%%%%%%% Partie III %%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%% S'efface si X est consistant avec Regle R si lorsqu'on a joute X à Regle, la Regle obtenu est une règle de Golomb à M+1 marques
consistant(X,R):- intervalles(R,Int), longueur(Int,MaxInt), longueur(R,MaxR), X is MaxInt+MaxR+1. 

%% Retire les éléments inconsistants
retire_el_inconsistant(L, R, LR) :- consistant(NextCons,R), retire_el(NextCons, L, LR). 

%% Ne garde que ceux consistant
retire_el_inc([],_,[]).
retire_el_inc([T|Q],R, [Tinc|Qinc]):- consistant(NextCons,R) , T >= NextCons, Tinc is T, retire_el_inc(Q, R, Qinc),!.
retire_el_inc([_|Q], R,L):- retire_el_inc(Q,R,L).   
