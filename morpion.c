#include <stdio.h>

int fin(int tab[]);
int demande_tour(int tab[], int player_id);
void affichage(int tab[]);

int main(){
	int tab[9];
	int i;

	for (i = 0;i < 9;i++){
		tab[i] = -1;
	}

	while(fin(tab) == 0){
		demande_tour(tab,1);
		if (fin(tab) != 0) continue;
		demande_tour(tab,2);
	}

	printf("Bravo !\n");

	return 1;
}

int demande_tour(int tab[], int player_id){
	int fin = 0;
	while (fin == 0){
		char r;
		int c = 0;
		affichage(tab);
		printf("Joueur %d : que voulez-vous faire ? ", player_id);
		do {
			scanf("%c", &r);
			if (r == ' ') c++;
			if (r == '\n') printf("Joueur %d : que voulez-vous faire ? ", player_id);
		} while ((r == ' ') && (c < 9));

		if (c >= 9) continue;

		if (tab[c] != -1){
		       	printf("Cette case a déjà été prise.\n");
			continue;
		}

		tab[c] = player_id;
		fin = 1;
	}

	return 1;
}

void affichage(int tab[]){
	int i;

	for (i = 0;i < 9;i++){
		if ((i == 3) || (i == 6)){
			printf("\n");
			printf("-----\n");	
		}
		switch(tab[i]){
			case -1 : printf(" ");
				  break;
			case 1 : printf("O");
				 break;
			case 2 : printf("X");
				 break;
			default : printf(" ");
				  break;
		}
		printf("I");
//		if ((i == 2) || (i == 5) || (i == 8)){
//			printf("\b");
//		}
	}
	printf("\n");


}

int fin(int tab[]){
	int oui = 0;
	int i;
	int non = 0;
	// Lignes horizontales joueur_1
	if ((tab[0] == 1) && (tab[1] == 1) && (tab[2] == 1)){
	       	oui = 1;
	}
	if ((tab[3] == 1) && (tab[4] == 1) && (tab[5] == 1)){
		oui = 1;
	}
	if ((tab[6] == 1) && (tab[7] == 1) && (tab[8] == 1)){
		oui = 1;
	}
	// Diagonales joueur_1
	if ((tab[0] == 1) && (tab[4] == 1) && (tab[8] == 1)){
		oui = 1;
	}
	if ((tab[2] == 1) && (tab[4] == 1) && (tab[6] == 1)){
		oui = 1;
	}
	// Lignes verticales joueur_1
	if ((tab[0] == 1) && (tab[3] == 1) && (tab[6] == 1)){
		oui = 1;
	}
	if ((tab[1] == 1) && (tab[4] == 1) && (tab[7] == 1)){
		oui = 1;
	}
	if ((tab[2] == 1) && (tab[5] == 1) && (tab[8] == 1)){
		oui = 1;
	}
	// Lignes horizontales joueur_2
	if ((tab[0] == 2) && (tab[1] == 2) && (tab[2] == 2)){
	       	oui = 2;
	}
	if ((tab[3] == 2) && (tab[4] == 2) && (tab[5] == 2)){
		oui = 2;
	}
	if ((tab[6] == 2) && (tab[7] == 2) && (tab[8] == 2)){
		oui = 2;
	}
	// Diagonales joueur_2
	if ((tab[0] == 2) && (tab[4] == 2) && (tab[8] == 2)){
		oui = 2;
	}
	if ((tab[2] == 2) && (tab[4] == 2) && (tab[6] == 2)){
		oui = 2;
	}
	// Lignes verticales joueur_2
	if ((tab[0] == 2) && (tab[3] == 2) && (tab[6] == 2)){
		oui = 2;
	}
	if ((tab[1] == 2) && (tab[4] == 2) && (tab[7] == 2)){
		oui = 2;
	}
	if ((tab[2] == 2) && (tab[5] == 2) && (tab[8] == 2)){
		oui = 2;
	}

	for(i = 0;i < 9;i++){
		if (tab[i] != -1){
			non++;
		}
	}

	if ((non == 9) && (oui == 0)){
		oui = 3;
	}


	switch(oui){
		case 1 : printf("Victoire du joueur 1 !!!\n");
			 break;
		case 2 : printf("Victoire du joueur 2 !!!\n");
			 break;
		case 0 : break;
		default : printf("Match nul.\n");
			  break;
	}

	return oui;
}