#include <stdio.h>
#define MAX_CARACTERES 128

void efface(int i,int max);

char texte[MAX_CARACTERES + 1];

int main(){
	int j;
	int i = 0;

	printf("Écrivez quelque chose (max : %d caractères) : ", MAX_CARACTERES);

	do {
		scanf("%c", &texte[i]);
		i++;
	} while ((i < MAX_CARACTERES) && (texte[i] != '\n'));

	for (j = 0;j < i;j++){
		if (texte[j] == 'e'){
		    efface(j,i);
			i--;
		}
	}

	printf("%s\n",texte);

	return 1;
}

void efface(int i,int max){

	while (i < max){
		texte[i] = texte [i + 1];
		i++;
	}

	texte[i] = '\n';

	return;
}