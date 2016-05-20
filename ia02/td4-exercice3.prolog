#!/usr/bin/gprolog --consult-file

succ(N,B,S):-
    reverse(N,NI),
    succI(NI,B,SI),
    reverse(SI,S).

succB(N,[N,M|_],M):-!.
succB(N,[_|Q],M):-succB(N,Q,M).

succI([_|Q],[R|P],[R|QP]):-succ(Q,[R|P],QP).
succI([],[_,S|_],S).