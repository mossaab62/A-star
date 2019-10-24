#include "fonctions.h"

void initLab(LAB l){
	int i = 0;
	int j = 0;
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			l[i][j]=0;
		}
	}
}

// /!\ l[colonnes][lignes]
void Lab1(LAB l){
	l[2][1]=l[2][2]=l[2][3]=l[2][4]=l[3][4]=1;
}

int rand_a_b(int a, int b){
	return(rand()%(b-a) +a);
}

/*Fonctions inutile de germain
void rdLab(LAB l){
	int i=0;
	int j=0;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			l[i][j]=rand_a_b(0,2);
		}
	}
}*/

/* Placement des bloques obstacle */
