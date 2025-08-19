#include <stdio.h>
#define ML 128
#define NP 10

void affiche(char c[], int x[], int y[]){
    int i;

    for (i = 0;i < NP;i++){
        printf("Point %c de coordonnées %d %d\n", c[i], x[i], y[i]);
    }
}

int main(){
    char ligne[ML];
    char c[NP];
    int x[NP], y[NP];
    int i;

    for(i = 0;i < NP;i++){
        printf("Donner un point (1 caractère) et deux coordonées : ");
        fgets(ligne, sizeof(ligne), stdin);
        sscanf(ligne, "%c %d %d", &c[i], &x[i], &y[i]);
    } 

    affiche(c,x,y);

    return 1;
}