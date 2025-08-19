#include <stdio.h>
#define LG_NOM 30

struct date {
    int jour;
    int mois; 
    int annee;
};

struct personne {
    char NOM[LG_NOM + 1];
    struct date date_embauche;
    struct date date_poste;
};

int remplissage(struct personne *employe){

    char c;
    int i;
    int jour;
    int mois; 
    int annee;

    i = 0;

    printf("Nom :");
    do {
        scanf("%c", &c);
        employe->NOM[i] = c;
        i++;
    } while (c != '\n');
    employe->NOM[--i] = '\0';

    printf("Date embauche (JJ MM AAAA) :");
    scanf("%d %d %d", &jour, &mois, &annee);
    employe->date_embauche.jour = jour;
    employe->date_embauche.mois = mois;
    employe->date_embauche.annee = annee;

    printf("Date poste = date embauche (O/N) ?");
    scanf("%c", &c);
    if ((c == 'O') || (c == 'o')){
        employe->date_poste.jour = employe->date_embauche.jour;
        employe->date_poste.mois = employe->date_embauche.mois;
        employe->date_poste.annee = employe->date_embauche.annee;
    } else {
        printf("Date poste (JJ MM AAAA) :");
        scanf("%d %d %d", &jour, &mois, &annee);
        employe->date_poste.jour = jour;
        employe->date_poste.mois = mois;
        employe->date_poste.annee = annee;
    }

    return 1;
}