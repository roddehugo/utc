//Atelier simulation commande d'une voiture
//prise en main de Scilab
clear //on efface les variables du workspace 
clc //on efface la console
close //on ferme une fenêtre

rouge=5 ;bleu=2 ;blanc=8 ;vert=3 ;noir=0 ;magenta=6 ;
//Il faut charger les fonctions quand elles sont déclarées dans un fichier externe
exec('load_map.sci');

//la carte est une polyligne fermée
m=load_map('MapLoop.txt');

//affichage de Seville
xpoly(m(1,:),m(2,:));
isoview(-300, -200, 280, 400);

//on parcourt la carte du début à la fin
//on affiche un point à chaque noeud
//n=size(m,2);
//for i=1:n
//    plot(m(1,i),m(2,i),'*r');
//    //xclick()
//end

exec('draw_voiture.sci');
x=[-220;360;0;0;0];
draw_voiture_ligne(x,bleu)

title('Terminé');

