#include <stdio.h>
#define MAX_POINTS 100

struct s_point {
	char c;
	int x, y;
};

void affiche (struct s_point point);
int remplir (struct s_point tab[]);

int main(){

	int i;
	int nb_points;
	struct s_point tab[MAX_POINTS];

	nb_points = remplir(tab);

	for (i = 0;i < nb_points;i++){
		affiche(tab[i]);
	}

	return 1;
}

void affiche(struct s_point point){

	printf("Point %c aux coordonnées x : %d et y : %d.\n", point.c, point.x, point.y);

	return;
}

int remplir(struct s_point   tab[]){
	int i = 0;

	do {
		printf("Donner une lettre majuscule ainsi que deux nombres entiers (point 0 pour terminer) : ");
		scanf("%c %d %d", &tab[i].c, &tab[i].x, &tab[i].y);
		i++;
	} while ((tab[i].c != '0') && (i < MAX_POINTS));
	
	return i;
}