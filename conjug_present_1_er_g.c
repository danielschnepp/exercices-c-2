#include <stdio.h>
#include <string.h>
#define LONGUEUR_MAX 30

void conjugaison(char verbe[],int longueur,int special);
int verification(char verbe[],int longueur,int *new);
int aller_verif(char verbe[],int longueur);

int main(){

	char verbe[LONGUEUR_MAX + 1] = {'\0'};
	int special;
	int oui;
	int longueur;

	do {
		oui = 0;

		printf("Donner un verbe du 1er groupe (en -er sauf 'aller') : ");
		scanf("%s", &verbe[0]);
		longueur = strlen(verbe);
		
		oui = verification(verbe,longueur,&special);

		if (oui == 0){
			printf("Svp un verbe du 1er groupe.\n");
		}

	} while (oui == 0);

	conjugaison(verbe,longueur,special);

	return 1;
}

void conjugaison(char verbe[],int longueur,int special){

	int i;
	int j;
	char terminaisons[6][3] = { {'e',' ',' '},{'e','s',' '},{'e',' ',' '},{'o','n','s'},{'e','z',' '},{'e','n','t'} };
	char pronoms[6][4] = { {'j','e',' ','\b'},{'t','u',' ','\b'},{'i','l',' ','\b'},{'n','o','u','s'},{'v','o','u','s'},{'i','l','s',' '} };

	for (i = 0;i < 6;i++){
		int k;
		for (k = 0;k < 4;k++){
			printf("%c",pronoms[i][k]);
		}
		printf(" ");
		for (k = 0;k < longueur - 2;k++){
			printf("%c", verbe[k]);
		}
		for (j = 0;j < 3;j++){
			if ((j == 0)){
				switch (special){
					case 1 : if (i == 3) printf("e");
						 break;
					case 2 : if (i == 3) printf("\bç");
						 break;
					case 3 : if (!((i == 3) || (i == 4))){
							 printf("t");
						 }
						 break;
				default : break;
				}
			}
			printf("%c", terminaisons[i][j]);
		}
		printf("\n");
	}
}


int verification(char verbe[],int longueur,int *new){

	if ((verbe[longueur - 2] != 'e') || (verbe[longueur - 1] != 'r') || (aller_verif(verbe,longueur))){
		return 0;
	}
	switch (verbe[longueur - 3]){
		case 't' : if (verbe[longueur - 4] == 'e') *new = 3;
			   break;
		case 'g' : *new = 1;
			   break;
		case 'c' : *new = 2;
			   break;
		default : *new = 0;
			  break;
	}
	return 1;
}

int aller_verif(char verbe[],int longueur){

	char aller[5] = {'a','l','l','e','r'};
	int oui = 0;
	int i;

	if (longueur != 5) return 0;
	for (i = 0;i < 5;i++){
		if (verbe[i] == aller[i]) oui++;
	}

	if (oui == 5){
		return 1;
	} else {
		return 0;
	}
}