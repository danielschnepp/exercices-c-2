#include <stdio.h>
#define ML 20


int affiche(int nb_ligne, int tab[ML][ML]){
    int i;
    int j;

    for (i = -3;i < nb_ligne;i++){
        switch(i){
            case -3 : printf(" p    ");
                      break;
            case -2 : printf(" n    ");
                      break;
            case -1 : printf("------");
                      break;
            default : printf("%2d --",i);
        }
        for (j = 0;j < nb_ligne;j++){
            switch(i){
                case -3 : printf("%5d",j);
                          break;
                case -2 : break;
                case -1 : printf("-----");
                          break;
                default : if (tab[i][j] != 0) printf("%5d", tab[i][j]);
            }
        }
        printf("\n");
    }

    printf("_____");
    for (i = 0;i < nb_ligne;i++){
        printf("_____");
    }
    printf("\n");

    return 1;
}

int ligne(int nb_ligne, int tab[ML][ML]){
    int i;
    int j;

    tab[0][0] = 1;
    
    for (i = 0;i < nb_ligne;i++){
        for(j = 0;j <= i;j++){
            if (j == 0){
                tab[i][j] = 1;
            } else {
            tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
            }
        }
    }

    affiche (nb_ligne, tab);

    return 1;
}

int main(){
    int nb_ligne;
    int tab[ML][ML] = { 0 };

    printf("Combien de ligne voulez-vous ? ");
    scanf("%d", &nb_ligne);
    if (nb_ligne > ML){
        printf("Nombre de ligne trop important.");
        return 0;
    }
    ligne(nb_ligne, tab);

    return 1;
}