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
		glp_set_col_kind(porb,i,GLP_BV); // type des variables
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

ia[6]  = 2  ; ja[6]  = 2  ; ar[6]  = 1.0 ;
ia[7]  = 2  ; ja[7]  = 15  ; ar[7]  = -1.0 ;
ia[8]  = 2  ; ja[8]  = 16  ; ar[8]  = -1.0 ;
ia[9]  = 2  ; ja[9]  = 17  ; ar[9]  = -1.0 ;
ia[10] = 2 ; ja[10] = 18 ; ar[10] = -1.0 ;
ia[11] = 2 ; ja[11] = 19 ; ar[11] = -1.0 ;

ia[12] = 3 ; ja[12] = 3 ; ar[12] = 1.0 ;
ia[13] = 3 ; ja[13] = 16 ; ar[13] = -1.0 ;
ia[14] = 3 ; ja[14] = 17 ; ar[14] = -1.0 ;

ia[15] = 4 ; ja[15] = 4 ; ar[15] = 1.0 ;
ia[16] = 4 ; ja[16] = 17 ; ar[16] = -1.0 ;
ia[17] = 4 ; ja[17] = 18 ; ar[17] = -1.0 ;
ia[18] = 4 ; ja[18] = 19 ; ar[18] = -1.0 ;
ia[19] = 4 ; ja[19] = 20 ; ar[19] = -1.0 ;
ia[20] = 4 ; ja[20] = 23 ; ar[20] = -1.0 ;
ia[21] = 4 ; ja[21] = 24 ; ar[21] = -1.0 ;

ia[22] = 5 ; ja[22] = 5 ; ar[22] = 1.0 ;
ia[23] = 5 ; ja[23] = 18 ; ar[23] = -1.0 ;
ia[24] = 5 ; ja[24] = 19 ; ar[24] = -1.0 ;
ia[25] = 5 ; ja[25] = 20 ; ar[25] = -1.0 ;
ia[26] = 5 ; ja[26] = 22 ; ar[26] = -1.0 ;
ia[27] = 5 ; ja[27] = 23 ; ar[27] = -1.0 ;
ia[28] = 5 ; ja[28] = 24 ; ar[28] = -1.0 ;

ia[29] = 6 ; ja[29] = 6 ; ar[29] = 1.0 ;
ia[30] = 6 ; ja[30] = 19 ; ar[30] = -1.0 ;
ia[31] = 6 ; ja[31] = 20 ; ar[31] = -1.0 ;
ia[32] = 6 ; ja[32] = 22 ; ar[32] = -1.0 ;
ia[33] = 6 ; ja[33] = 23 ; ar[33] = -1.0 ;
ia[34] = 6 ; ja[34] = 24 ; ar[34] = -1.0 ;

ia[35] = 7 ; ja[35] = 7 ; ar[35] = 1.0 ;
ia[36] = 7 ; ja[36] = 20 ; ar[36] = -1.0 ;
ia[37] = 7 ; ja[37] = 21 ; ar[37] = -1.0 ;
ia[38] = 7 ; ja[38] = 22 ; ar[38] = -1.0 ;
ia[39] = 7 ; ja[39] = 23 ; ar[39] = -1.0 ;
ia[40] = 7 ; ja[40] = 24 ; ar[40] = -1.0 ;

ia[41] = 8 ; ja[41] = 8 ; ar[41] = 1.0 ;
ia[42] = 8 ; ja[42] = 21 ; ar[42] = -1.0 ;
ia[43] = 8 ; ja[43] = 22 ; ar[43] = -1.0 ;
ia[44] = 8 ; ja[44] = 23 ; ar[44] = -1.0 ;
ia[45] = 8 ; ja[45] = 24 ; ar[45] = -1.0 ;
ia[46] = 8 ; ja[46] = 25 ; ar[46] = -1.0 ;
ia[47] = 8 ; ja[47] = 26 ; ar[47] = -1.0 ;

ia[48] = 9 ; ja[48] = 9 ; ar[48] = 1.0 ;
ia[49] = 9 ; ja[49] = 22 ; ar[49] = -1.0 ;
ia[50] = 9 ; ja[50] = 23 ; ar[50] = -1.0 ;
ia[51] = 9 ; ja[51] = 24 ; ar[51] = -1.0 ;
ia[52] = 9 ; ja[52] = 25 ; ar[52] = -1.0 ;

ia[53] = 10 ; ja[53] = 10 ; ar[53] = 1.0 ;
ia[54] = 10 ; ja[54] = 23 ; ar[54] = -1.0 ;
ia[55] = 10 ; ja[55] = 24 ; ar[55] = -1.0 ;
ia[56] = 10 ; ja[56] = 25 ; ar[56] = -1.0 ;

ia[57] = 11 ; ja[57] = 11 ; ar[57] = 1.0 ;
ia[58] = 11 ; ja[58] = 24 ; ar[58] = -1.0 ;
ia[59] = 11 ; ja[59] = 25 ; ar[59] = -1.0 ;

ia[60] = 12 ; ja[60] = 12 ; ar[60] = 1.0 ;
ia[61] = 12 ; ja[61] = 25 ; ar[61] = -1.0 ;
ia[62] = 12 ; ja[62] = 26 ; ar[62] = -1.0 ;

ia[63] = 13 ; ja[63] = 13 ; ar[63] = 1.0 ;
ia[64] = 13 ; ja[64] = 26 ; ar[64] = -1.0 ;

return 0;
}

