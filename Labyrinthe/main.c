#include "fonctions.h"

int main(void){
	//Initialisation du tableau et de la liste ayant les coordonnais de depart et d'arrive
	LAB l;
	LIS pos;

	//Fonction utilise pour les nombre aleatoire NE PAS TOUCHE
	srand(time(NULL));

	//Initialise la grille, place les obstacles et les points de departs
	initLab(l);
	obstacles(l);
	init2(l,pos);
	
	//a* ici
	parcour(l,pos);

	//Permet d'afficher le tableau
	printLAB(l);

	return 0;
}
