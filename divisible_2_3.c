#include <stdio.h>

int divise_2(int);
int divise_3(int);
int divise_6(int);

int main(){
	int n;

	printf("Donner un nombre entier : ");
	scanf("%d", &n);

	if (divise_2(n)) printf("%d est divisible par 2.\n", n);
	if (divise_3(n)) printf("%d est divisible par 3.\n", n);
	if (divise_6(n)) printf("Par conséquant, %d est divisible par 6.\n", n);

	return 1;
}

int divise_2(int n){
	if ((n % 2) == 0){
		return 1;
	} else {
		return 0;
	}
}

int divise_3(int n){
	if ((n % 3) == 0){
		return 1;
	} else {
		return 0;
	}
}

int divise_6(int n){
	if (divise_2(n) && divise_3(n)){
		return 1;
	} else {
		return 0;
	}
}