%% Flatten

myflatten([],X).
myflatten([T|Q],LF):-flatten(T,LI),flatten(Q,LP),append(LI,LP,LF),!.
myflatten(X,[X]).

%% Element
element(X,[X|_],1).
element(X,[_|Q],N):-element(X,Q,M),N is M+1.

%% Successeur
succ(N,B,S):-
    reverse(N,NI),
    succI(NI,B,SI),
    reverse(SI,S).

succB(N,[N,M|_],M):-!.
succB(N,[_|Q],M):-succB(N,Q,M).

succI([_|Q],[R|P],[R|QP]):-succ(Q,[R|P],QP).
succI([],[_,S|_],S).

%% Fermier,Chevre,Loup,Salade
solve(EF,EF,_,[]).
solve(E,EF,H,[M|MVTS]):-move(E,M,ES),valid(ES),element(ES,H),solve(ES,EF,[ES|H],MVTS).

%on doit choisir la representation des états
%on doit écrire les prédicats move et valid
%on utilise deux structures complexes de quadruplet
%[(1,1,1,1),(0,0,0,0)]
%  fermier,chevre,loup,salade

valid(E):-\+invalid(E).
invalid([(0,1,1,_),_]).
invalid([_,(0,1,1,_)]).
invalid([(0,1,_,1),_]).
invalid([_,(0,1,_,1)]).

move([(1,1,LG,SG),(0,0,LD,SD)], vers_droite(c), [(0,0,LG,SG),(1,1,LD,SD)]).
move([(1,CG,1,SG),(1,1,LD,)])