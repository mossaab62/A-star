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

// Place 2 obstacle en prenant compte de la dimension de la grille
void obstacles(LAB l){
	int i;
	int j;
	//block 1(carre)
	i=rand() % 9;
	j=rand() % 9;
	l[i][j]=l[i+1][j]=l[i][j+1]=l[i+1][j+1]=1;
	//block 2(L)
	i=rand() % 7;
	j=rand() % 7;
	l[i][j]=l[i][j+1]=l[i][j+2]=l[i][j+3]=l[i+1][j+3]=1;

}
//Definie le point de depart et le point d'arrive en prenant compte de la presense ou non d'obstacle
void init2(LAB l,LIS pos){
	int ya;
	int xa;
	int yb;
	int xb;
	int testa = 0;
	int testb = 0;
	while(testa==0)
	{
		ya=rand() % DIM;
		xa=rand() % DIM;
		if (l[ya][xa] == 0) testa=1 ; 
	}
	while(testb==0)
	{
		yb=rand() % DIM;
		xb=rand() % DIM;
		if (l[yb][xb] == 0) testb=1 ;
	}
	pos[0]=ya;
	pos[1]=xa;
	pos[2]=yb;
	pos[3]=xb;
	l[ya][xa]=2;
	l[yb][xb]=4;
}

int rand_a_b(int a, int b){
	return(rand()%(b-a) +a);
}

/*Affiche le tableau*/
void printLAB(LAB l){
	int i,j;
	for(i = 0; i < DIM; i++){

        for(j = 0; j < DIM; j++){
			//cette partie permet de colore les valeurs dans le tableau pour mieux voir leur disposition
			if (l[i][j]==1)
			{
				printf("\033[1;31m");
				printf("%d\t", l[i][j]);
			}
			if (l[i][j]==2)
			{
				printf("\033[0;32m");
				printf("%d\t", l[i][j]);
			}
			if (l[i][j]==4)
			{
				printf("\033[1;34m");
				printf("%d\t", l[i][j]);
			}
            if (l[i][j]==0)
			{
				printf("\033[0m");
				printf("%d\t", l[i][j]);
			}
			if (l[i][j]==3)
			{
				printf("\033[0;35m");
				printf("%d\t", l[i][j]);
			}

        }

        printf("\n");

    }
	printf("\n");
}

/* Calcule distance euclidienne entre 2 point*/
float distance(int ya, int xa,int yb ,int xb){
	float d;
	d=pow( pow (abs(ya - yb) ,2) + pow(abs(xa - xb) ,2) , 0.5 );
	return d;
}

//Position du min dans dist et modifie positionmin en ajoutant l'ecart au point central dans la direction du min
void position_min(DIS dist,POSMIN positionmin){
	int min=dist[0];
	int i=0;
	int j;
	for (j = 0; j < 8; j++)
	{
		if (dist[j]<=min)
		{
			min=dist[j],i=j;
		}
	}

	if (i==0) positionmin[0]=-1,positionmin[1]=-1 ;
	if (i==1) positionmin[0]=-1,positionmin[1]=0  ;
	if (i==2) positionmin[0]=-1,positionmin[1]=+1 ;
	if (i==3) positionmin[0]=0,positionmin[1]=-1  ;
	if (i==4) positionmin[0]=0,positionmin[1]=+1  ;
	if (i==5) positionmin[0]=+1,positionmin[1]=-1 ;
	if (i==6) positionmin[0]=+1,positionmin[1]=0  ;
	if (i==7) positionmin[0]=+1,positionmin[1]=+1 ;
}

//Trace le chemin le plus court vers le point d'arrive
void parcour(LAB l,LIS pos){
	int i=pos[0];
	int j=pos[1];
	int a=0;
	DIS dist;
	POSMIN positionmin;
	while((i!=pos[2] || j!=pos[3]) && a < 50){
		//si il n'est pas possible d'aller dans un dirrection la valeur reste a 1000, etant superieu au distance que l'on calcule elle ne peux jamais etre choisi comme min
		dist[0]=dist[1]=dist[2]=dist[3]=dist[4]=dist[5]=dist[6]=dist[7]=1000;

		if(i-1>=0 && j-1>=0 && i-1<10 && j-1<10 &&  l[i-1][j-1]!=1  ) dist[0]=distance(i-1,j-1,pos[2],pos[3]);
		if(i-1>=0 && j>=0   && i-1<10 && j<10   &&  l[i-1][j]!=1)   dist[1]=distance(i-1,j,pos[2],pos[3]);
		if(i-1>=0 && j+1>=0 && i-1<10 && j+1<10 &&  l[i-1][j+1]!=1) dist[2]=distance(i-1,j+1,pos[2],pos[3]);
		if(i>=0   && j-1>=0 && i<10   && j-1<10 &&  l[i][j-1]!=1)   dist[3]=distance(i,j-1,pos[2],pos[3]);
		if(i>=0   && j+1>=0 && i<10   && j+1<10 &&  l[i][j+1]!=1)   dist[4]=distance(i,j+1,pos[2],pos[3]);
		if(i+1>=0 && j-1>=0 && i+1<10 && j-1<10 &&  l[i+1][j-1]!=1) dist[5]=distance(i+1,j-1,pos[2],pos[3]);
		if(i+1>=0 && j>=0   && i+1<10 && j<10   &&  l[i+1][j]!=1)   dist[6]=distancer(i+1,j,pos[2],pos[3]);
		if(i+1>=0 && j+1>=0 && i+1<10 && j+1<10 &&  l[i+1][j+1]!=1) dist[7]=distance(i+1,j+1,pos[2],pos[3]);
		//Recherche du min et moddification de i et j
		position_min(dist,positionmin);
		i+=positionmin[0];
		j+=positionmin[1];
		if (l[i][j]!=4)
		{
			l[i][j]=3;
		}
		a++;
		printLAB(l);
	}
}