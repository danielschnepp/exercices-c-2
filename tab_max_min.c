#include <stdio.h>

int cherche_max_val(void);
int cherche_min_val(void);
int tab[10];


int main(){

	tab[0] = 7;
	tab[1] = 0;
	tab[2] = 4;
	tab[3] = 3;
	tab[4] = 5;
	tab[5] = 8;
	tab[6] = 2;
	tab[7] = 6;
	tab[8] = 1;
	tab[9] = 9;

	int min = cherche_min_val();
	int max = cherche_max_val();

	printf("Valeur la plus petite : %d\n", min);
	printf("Valeur la plus grande : %d\n", max);

	return 1;
}

int cherche_max_val(){
	int max = -1;
	int i;

	for (i = 0;i < 10;i++){
		if (tab[i] > max){
			max = tab[i];
		}
	}

	return max;
}

int cherche_min_val(){
	int min = 1000;
	int i;

	for (i = 0;i < 10;i++){
		if (tab[i] < min){
			min = tab[i];
		}
	}

	return min;
}