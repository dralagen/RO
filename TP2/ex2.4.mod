/* ex2.4 */

param N; # nombre de machines ou de peronne
set I := 1..N; # indice

param perMach{I,I}; # matrice des couts

var X{I,I} binary; # affectation personne i pour la machine j

# fonction Objectif

maximize z : sum{i in I, j in I} perMach[i,j]*X[i,j] ;

# contraintes
s.t. personne{i in I} : sum{j in I} X[i,j] = 1; # chaque personnes ne peut etre affecté qu'a une machine
s.t. machine{j in I} : sum{i in I} X[i,j] = 1; # chaque machines peut avec qu'une personnes


# résolution

solve;

display : X;
display : "z=", sum{i in I, j in I} perMach[i,j]*X[i,j];

# données

data;

param N := 6;

param perMach : 1 2 3 4 5 6 :=
1 13 24 31 19 40 29
2 18 25 30 15 43 22
3 20 20 27 25 34 33
4 23 26 28 18 37 30
5 28 33 34 17 38 20
6 19 36 25 27 45 24
;



end;
