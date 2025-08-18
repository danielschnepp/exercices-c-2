#include <stdio.h>

int main(){
	int ligne;
	int i;
	int j;

	printf("Nombre de ligne(s) : ");
	scanf("%d", &ligne);

	for (i = 0;i < ligne;i++){
		for (j = 0;j < (ligne - i - 1);j++){
			printf(" ");
		}
		for (j = 0;j < (1 + 2 * i);j++){
			printf("*");
		}
		printf("\n");
	}

	return 1;
}