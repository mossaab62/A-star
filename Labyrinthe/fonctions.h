#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define DIM 10

typedef int LAB[DIM][DIM];
typedef int LIS[4];
typedef float DIS[8];
typedef int POSMIN[2];

//initialise la grille en la remplissant de 0
void initLab(LAB);

//place les obstacles dans la grille
void obstacles(LAB);

//Definie le point de depart et le point d'arrive en prenant compte de la presense ou non d'obstacle
void init2(LAB,LIS);

//permet de sortir un nombre aleatoire entre a inclu et b exclu
int rand_a_b(int, int);

/* Permet d'afficher un tableau l de dimmension DIM*DIM avec des couleur :) */
void printLAB(LAB);

/* Calcule distance euclidienne entre deux point (exemple l[ya][xa] et l[yb][xb]) */
float distance(int ya, int xa,int yb ,int xb);

//Determine la position ou la distance et la plus petit et modifie posmin en donnant l'ecart a la position 
//exemple: si le chemin le plus court et en haut -> posmin={-1,0} -> i+=-1 j+=0 dans la fonction parcour
void position_min(DIS,POSMIN);

//fait le parcour le plus cour pour aller du point de depart au point d'arrive
void parcour(LAB,LIS);
