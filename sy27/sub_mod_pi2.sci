function e=sub_mod_pi2(x,y)
//pour 2 angles passés en paramètre, calcul l'écart e=x-y 
//retourne une valeur entre -%pi et %pi
//fct utile pour calculer des écarts angulaires dans des commandes 
//car un écart angulaire de commande doit rester petit
if (x>=y) then
    while norm(x-y)>%pi
        x=x-2*%pi
    end
else
    while norm(x-y)>%pi
        y=y-2*%pi
    end
end    
e=x-y;
endfunction
