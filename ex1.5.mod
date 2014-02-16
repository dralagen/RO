/*  ex1.5

execute : glpsol --model ex1.5.mod --data ex1.5.dat

*/

# Paramètres

param nbMois;        # nombre de mois
set I := 1..nbMois;  # indice des mois de prévision
set I2 := 2..nbMois; # indice des autres mois


param coutProd;      # cout de production en heure normal pour 1 velo
param coutProdSup;   # cout de production en heure supplémentaire pour 1 vélo
param coutStock;     # cout de stock pour 1 vélo

param stockInit;     # stock initial de vélo
param capaProd;      # capacité de production en 1 mois

param previ{I};      # prévision pourle mois i

# Variables

var XP{I} >= 0 integer;   # nb de vélo produit au mois i
var XSUP{I} >= 0 integer; # nb de vélo produit en heure sup au mois i
var XST{I} >= 0 integer;  # nb de vélo stocker a la fin du mois i

# fonction Objectif

minimize cout: sum{i in I}( coutProd*XP[i]
														+
														coutProdSup*XSUP[i]
														+
														coutStock*XST[i] );

# contraintes

s.t. premierMois : XP[1]+XSUP[1]+stockInit = previ[1] + XST[1];
s.t. autresMois{i in I2} : XP[i]+XSUP[i]+XST[i-1] = previ[i] + XST[i];
s.t. exesProduction{i in I} : XP[i] <= capaProd;

solve;

# display
display : XP;
display : XST;
display : "z=", sum{i in I}( coutProd*XP[i]
														 +
														 coutProdSup*XSUP[i]
														 +
														 coutStock*XST[i] );

end;

