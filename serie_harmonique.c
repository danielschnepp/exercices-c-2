#include <stdio.h>

int main(){
	int i;
	int n;
	double som = 0;

	printf("Donner un nombre : ");
	scanf("%d", &n);

	for (i = 1;i <= n;i++){
		som += (float) 1 / i;
	}

	printf("%f\n", som);

	return 1;
}