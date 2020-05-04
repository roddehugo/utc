//Atelier simulation commande d'une voiture
//prise en main de Scilab
clear //on efface les variables du workspace 
clc //on efface la console
close //on ferme une fenêtre

rouge=5 ;bleu=2 ;blanc=8 ;vert=3 ;noir=0 ;magenta=6 ;

exec('draw_voiture_ligne.sci');
exec('system_state.sci');

//x=(y,theta)
x=[-1;0];
v=10;
u=%pi/6;
L=2;

//définition des poles
s1=-2;
s2=-2;

//calcul des gains
a1=s1*s2;
a2=-s1-s2;

//pour les saturations
u_max=%pi/8;
u_min=-u_max;

//consigne
zd=4;

duree_simu=5; //en secondes
Te=0.02; //période
t=[0:Te:duree_simu];

n=length(t);
for k=1:n,
    z=g(x);
    
    u=(L/v^2) * (a1*(zd-z) + a2*(0-v*x(2)));
    u=min(u,u_max);
    u=max(u,u_min);
    
    _x=f(x,u,v,L);
    x=x + Te*_x;
    
    
    drawlater();
    delete(gca());
    isoview(-6,6,-3,8);
    draw_voiture_ligne([x;v;u],zd,noir);
    drawnow();
end;
title('Terminé');
