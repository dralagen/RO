/*   ex1.1

execute : glpsol --model ex1.1.mod --data ex1.1.dat

 */

# Paramètres / Variables

param nbCasquette;       # nombre de type de casquette
set I := 1..nbCasquette;
param nbAtelier;         # nombre d'atelier pour fabriquer une casquette
set J := 1..nbAtelier;

param profit{I};         # profit de la casquette i
param tmpsFab{I,J};      # temps de fabrication de la casquette i dans l'atelier j
param heureDispo{J};     # heure dispo pour l'atelier j

var x{I} >= 0 integer;   # nb casquette i fabriqué

# fonction objectif

maximize profitTotal: sum{i in I}(profit[i]*x[i]);

# contraintes

s.t. tmps{j in J} : sum{i in I}(tmpsFab[i,j] * x[i]) <= heureDispo[j];

# affichage

solve;

display : x;
display : "z=", sum{i in I}(profit[i]*x[i]);

end;

