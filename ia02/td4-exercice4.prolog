#!/usr/bin/gprolog --consult-file

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