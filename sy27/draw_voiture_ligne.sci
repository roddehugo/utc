function draw_voiture_ligne(x,consigne_laterale,couleur)
    //x=(y,theta,v,delta)
    x=[0;x]; //on fixe x=0 arbitrairement
    //Chassis en coordonnées homogènes dans le repère véhicule
    M=[-1  4 5  5 4 -1 -1   -1 0  0  -1  1  0 0 -1 1 0 0 3 3 3;  ...
      -2 -2 -1 1 2 2  -2   -2 -2 -3 -3 -3 -3 3  3 3 3 2 2 3 -3;...
      ones(1,21)] ;
    //transformation homogène 2D pour transformer tous les points du chassis
    //dans le repère de travail
    T=[cos(x(3)),-sin(x(3)),x(1);...
       sin(x(3)), cos(x(3)),x(2) ;...
       0 0 1];
    M=T*M ; 
   
    Rav=[-1 1;0 0;1 1];  //Motif d'une roue avant
    Ravd=T*[cos(x(5)),-sin(x(5)) 3;sin(x(5)),cos(x(5)) 3 ;0 0 1]*Rav;
    Ravg=T*[cos(x(5)),-sin(x(5)) 3;sin(x(5)),cos(x(5)) -3;0 0 1]*Rav;
    xset("thickness",2) ; xset("color",couleur) ; 
   
    xpoly(M(1, :),M(2, :)) ;//dessine la voiture
    xpoly(Ravd(1,:),Ravd(2,:));
    xpoly(Ravg(1,:),Ravg(2,:));
    plot([-5 10], [consigne_laterale consigne_laterale])
endfunction ;
