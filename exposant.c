#include <stdio.h>

int main(){
    double long resultat = 1;
    double valeur;
    int i;

    printf("Donner un nombre réel et un exposant entier : ");
    scanf("%lf%d", &valeur, &i);
    printf("%f exposant %d vaut environ : ", valeur, i);

    if (i > 0){
        while(i > 0){
            resultat *= valeur;
            i--;
        }
    } else {
        while (i < 0){
            resultat *= valeur;
            i++;
        }
        resultat = 1 / resultat;
    }

    printf("%Lf\n", resultat);

    return 1;
}