/*
 * TP3 ex2.8
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>

#define NBVILLE 13
#define INDICE NBVILLE*2

#define NBVAR INDICE
#define NBCONTR NBVILLE

int main(int argc, char const *argv[]) {

	glp_prob *prob;

	int ia[1 + INDICE];
	int ja[1 + INDICE];
	double ar[1 + INDICE];

	int i;
	double z;
	double x[NBVAR];

	int p[NBVILLE];

	p[0]  = 53;
	p[1]  = 46;
	p[2]  = 16;
	p[3]  = 28;
	p[4]  = 96;
	p[5]  = 84;
	p[6]  = 32;
	p[7]  = 21;
	p[8]  = 15;
	p[9]  = 22;
	p[10] = 41;
	p[11] = 53;
	p[12] = 66;


	///////////////////////////////
	// Résolution du problème /////
	///////////////////////////////

	prob = glp_create_prob(); // déclaration d'un problème
	glp_set_prob_name(prob, "Coca"); // nom problème
	glp_set_obj_dir(prob, GLP_MAX); // direction objectif

	glp_add_rows(prob, NBCONTR); // nb contraintes

	for (i = 1; i <= NBCONTR; ++i) {
		glp_set_row_bnds(prob,i,GLP_UP, 0.0, 0.0); //borne contrainte
	}

	for (i = 1; i <= NBVAR; ++i) {
		glp_set_col_kind(porb,i,GLP_BV); // tyoe des variables
	}

	for (i = 1; i <= NBVILLE; ++i) {
		glp_set_obj_coef(prob,i,p[i]);
	}

/*****************
 *  contraintes  *
 *****************/

ia[1]  = 1  ; ja[1]  = 1  ; ar[1]  = 1.0 ;
ia[2]  = 1  ; ja[2]  = 14 ; ar[2]  = -1.0;
ia[3]  = 1  ; ja[3]  = 15 ; ar[3]  = -1.0 ;
ia[4]  = 1  ; ja[4]  = 16 ; ar[4]  = -1.0 ;
ia[5]  = 1  ; ja[5]  = 17 ; ar[5]  = -1.0 ;
ia[6]  = 6  ; ja[6]  = 6  ; ar[6]  = -1.0 ;
ia[7]  = 7  ; ja[7]  = 7  ; ar[7]  = -1.0 ;
ia[8]  = 8  ; ja[8]  = 8  ; ar[8]  = -1.0 ;
ia[9]  = 9  ; ja[9]  = 9  ; ar[9]  = -1.0 ;
ia[10] = 10 ; ja[10] = 10 ; ar[10] = -1.0 ;
ia[11] = 11 ; ja[11] = 11 ; ar[11] = -1.0 ;
ia[12] = 12 ; ja[12] = 12 ; ar[12] = -1.0 ;
ia[13] = 13 ; ja[13] = 13 ; ar[13] = -1.0 ;
ia[14] = 14 ; ja[14] = 14 ; ar[14] = -1.0 ;
ia[15] = 15 ; ja[15] = 15 ; ar[15] = -1.0 ;
ia[16] = 16 ; ja[16] = 16 ; ar[16] = -1.0 ;
ia[17] = 17 ; ja[17] = 17 ; ar[17] = -1.0 ;
ia[18] = 18 ; ja[18] = 18 ; ar[18] = -1.0 ;
ia[19] = 19 ; ja[19] = 19 ; ar[19] = -1.0 ;
ia[20] = 20 ; ja[20] = 20 ; ar[20] = -1.0 ;
ia[21] = 21 ; ja[21] = 21 ; ar[21] = -1.0 ;
ia[22] = 22 ; ja[22] = 22 ; ar[22] = -1.0 ;
ia[23] = 23 ; ja[23] = 23 ; ar[23] = -1.0 ;
ia[24] = 24 ; ja[24] = 24 ; ar[24] = -1.0 ;
ia[25] = 25 ; ja[25] = 25 ; ar[25] = -1.0 ;
ia[26] = 26 ; ja[26] = 26 ; ar[26] = -1.0 ;
ia[27] = 27 ; ja[27] = 27 ; ar[27] = -1.0 ;
	return 0;
}

