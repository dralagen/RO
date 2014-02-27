/* TP2 exercice 1 */

# paramètres

param n; #nb ligne
param m; #nb Colone

set indRow := 1..m; # indice des contraintes
set indCol := 1..n; # indice des variables

set Matcr dimen 2; # Matrice des contraintes

param obj{indCol}; # coeff variables

#

var x{indCol} binary;

# function obj

maximize z : sum{i in indCol} obj[i]*x[i];

# contraintes
s.t. contrainte{i in indRow} : sum{(i,j) in Matcr} x[j] <= 1;


solve;

display : x;
display : "objectif : ",   sum{i in indCol} obj[i]*x[i];

end;

