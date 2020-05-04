//Modèle d'observation par rapport à la carte
function [d,p]=gc(x)  
    //x=(x,y,theta)
    //retourne l'écart latéral signé et la pente du segment matché
    global m
    //affichage de Seville
    xpoly(m(1,:),m(2,:));
    isoview(-320, -200, 290, 390);
    //map matching    
    //recherche de la distance au point le plus proche sur le circuit
    M=[x(1);x(2)];
    d=%inf;
    e=%inf;
    indice=1;
    for j=indice:(size(m,2)-1)
        A=m(:,j);
        B=m(:,j+1);
        [di,pi]=ecart_pente_frenet(A,B,x);
        ei=sub_mod_pi2(pi,x(3));//ecart angulaire 
        //on cherche le segment qui minimise l'écart et la distance
        if (abs(di)+abs(ei))<(abs(d)+abs(e))
            d=di;
            p=pi;
            e=ei;
            indice = j;
        end
    end

    //segment qui va de A vers B
    A=m(:,indice); B=m(:,indice+1);
    plot(A(1), A(2),'*g');plot(B(1), B(2),'r*')
endfunction
