#include <stdio.h>
#include <math.h>

int main(){

    int nb;
    double racine;

    do {
        printf("Donnez un nombre positif : ");
        scanf ("%d", &nb);

        if (nb > 0) {
            racine = sqrt(nb);
            printf("Sa racine carrée est : %e\n", racine);
        } else if (nb < 0) {
            printf("Svp positif\n");
        }
    } while (nb != 0);

    return 1;
}