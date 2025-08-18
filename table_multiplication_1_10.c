#include <stdio.h>

int main(){
	int i;
	int j;

	// Haut de la table 
	
	printf("    I");

	for (i = 1;i <= 10; i++){
		printf(" %2d ", i);
	}
	printf("\n");
	printf("--------------------------------------------\n");

	// Corps et côté gauche de la table

	for (i = 1;i <= 10;i++){
		printf(" %2d I", i);

		for(j = 1;j <= 10;j++){
			printf("%3d ", i * j);
		}

		printf("\n");
	}

	return 1;
}