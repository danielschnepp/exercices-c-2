#include <stdio.h>
#define MAX_CARACTERES 1024

int main(){
	char tab[MAX_CARACTERES + 1] = { 'a' };
	int i = -1;
	int nb_e = 0;

	printf("Écrivez quelque chose (max : %d caractères) : ", MAX_CARACTERES);

	do {
		i++;
		scanf("%c", &tab[i]);
		if (tab[i] == 'e') nb_e++;

	} while ((i < MAX_CARACTERES) && (tab[i] != '\n'));

	printf("Il y a %d fois le caractère 'e' dans : ", nb_e);

	for(i = 0;(tab[i] != '\n') && (i < MAX_CARACTERES);i++){
		printf("%c",tab[i]);
	}
	printf("\n");

	return 1;
}