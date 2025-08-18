#include <stdio.h>

struct s_point {
	char c;
	int x, y;
};

void mise_a_zero(struct s_point *point);
struct s_point oppose(struct s_point point);

int main(){

	struct s_point point;

	mise_a_zero(&point);

	printf("Le point %c se trouve aux coordonnées :\nx : %d\ny : %d\n", point.c, point.x, point.y);

	printf("Donner une lettre majuscule et deux nombres entiers : ");

	scanf("%c %d %d", &point.c, &point.x, &point.y);

	printf("Le point %c se trouve aux coordonnées :\nx : %d\ny : %d\n", point.c, point.x, point.y);

	point = oppose(point);

	printf("Le point %c se trouve aux coordonnées :\nx : %d\ny : %d\n", point.c, point.x, point.y);

	return 1;
}

void mise_a_zero(struct s_point *point){

	point->c = '0';
	point->x = 0;
	point->y = 0;

	return;
}

struct s_point oppose(struct s_point point){

	point.x = -point.x;
	point.y = -point.y;

	return point;
}