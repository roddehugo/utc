%% 2 populations (alphabet) : + , -
%% A un instant t, sequence de + et de -

%% permutations
%% i) a + - b --> a - + b
%% ii) a - + b --> a + - b 

%% degustations
%% iii) a + - + b --> a + + b
%% iv) a - + - b --> a + + b

%% procreations
%% v) a + + b --> a + + + b
%% vi) a - - b --> a - - - b

%% cout elementaire 1
%% But du créateur de populations : faire atteindre un etat mono racial

%% + encerclé : a - b i g - d
%% - encerclé: a + b i g + d

%% lorque h() est minorante alors l'algo A devient A*

%% a) Appliquer A* à la situation : + + + - -
%% b) montrer h minorante
%% c) restriction monotone