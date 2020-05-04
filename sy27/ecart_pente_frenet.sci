function [d,p]=ecart_pente_frenet(A,B,x)
    //Le repère de Frenet a A pour origine et B définit l'axe x
    //x est une position (ou bien une pose 2D)
    //d= ecart latéral signé
    //p= pente signée du segment [AB]
    //PhB nov 2015
    M = x(1:2);
    xa=A(1);ya=A(2);
    xb=B(1);yb=B(2);
    alpha=atan((yb-ya),(xb-xa));
    //mat homogène
    O_T_A=[cos(alpha), -sin(alpha), xa;...
           sin(alpha),  cos(alpha), ya;...
            0      ,    0 ,          1 ;]
    //dans RA (repère de frenet)
    A_M = inv(O_T_A)*[M;1];
    axm=A_M(1);aym=A_M(2);
    
    A_B = inv(O_T_A)*[B;1]
    axb=A_B(1);ayb=A_B(2);
    
    if (axm<0) then
        d=sign(aym)*norm(A-M);
    elseif (axm>axb) then
        d=sign(aym)*norm(B-M);
    else
        d=aym;
    end
    p=alpha;
endfunction
