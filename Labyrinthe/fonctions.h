#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 6

typedef int LAB[DIM][DIM];
//initialise la grille en la remplissant de 0
void initLab(LAB);
//place l'obstacle
void Lab1(LAB);

int rand_a_b(int, int);

/* void rdLab(LAB); */
