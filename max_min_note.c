#include <stdio.h>

int main(){
	int n = 0;
	int max = 0;
	int min = 20;
	int nb_max = 0;
	int nb_min = 0;

	do {
		printf("Donner une note entière entre 0 et 20 inclus (-1 pour finir) : ");
		scanf("%d", &n);

		if ((n >= 0) && (n <= 20)){

			if (n > max){
			       	max = n;
				nb_max = 1;
			} else if (n == max){
			       	nb_max++;
			}
			if (n < min){
				min = n;
				nb_min = 1;
			} else if (n == min){
			       	nb_min++;
			}
		
		} else if (n == -1){

			if (max < min){
				printf("Attention : vous n'avez pas donné de notes !\n");
				return 1;
			}
		} else {
			printf("Svp entre 0 et 20 inclus.\n");
		}
	} while (n != -1);

	printf("La note maximale est %d. Elle a été donnée %d fois.\n", max, nb_max);
	printf("La note minimale est %d. Elle a été donnée %d fois.\n", min, nb_min);

	return 1;
}