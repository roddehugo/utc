#!/usr/bin/gprolog --consult-file

element(X,[X|_],1).
element(X,[_|Q],N):-element(X,Q,M),N is M+1.