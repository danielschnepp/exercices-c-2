#include <stdio.h>

int main(){
	int n1;
	int n2;
	int n3 = 0;
	int nb;
	int i;
	
	do {

		printf("Donner un nombre strictement supérieur à 2 : ");
		scanf("%d", &nb);

		if (!(nb > 2)) {
			printf("Svp supérieur à 2.\n");
		}

	} while (!(nb > 2));

	n1 = 0;
	n2 = 1;
	i = 1;

	while (i < nb){
		n3 = n1 + n2;

		if (n3 < 1){
			printf("Valeur trop grande.\n");
			return 1;
		}
		n2 = n1;
		n1 = n3;
		i++;
	}

	printf("Le %dème nombre dans la suite de Fibonnachi est %d.\n", nb, n3);

	return 1;
}