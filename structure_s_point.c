#include <stdio.h>
#define NP 15   // Nombre de points dans la courbe
#define LM 128 // Nombre maximum de caractères dans une ligne

struct s_point{
    char c;
    int x, y;
};

struct s_point courbe[NP];

void affiche_point (struct s_point point){
    printf("point %c de coordonnées %d %d\n", point.c, point.x, point.y);
}

void affiche_courbe (void){
    int i;

    for (i = 0;i < NP;i++){
        affiche_point(courbe[i]);
    }
}

void reset(struct s_point *point){
    point->c = 0;
    point->x = 0;
    point->y = 0;
}

struct s_point oppose(struct s_point point){
    struct s_point point_op;

    point_op.c = point.c;
    point_op.x = -point.x;
    point_op.y = -point.y;

    return point_op;
}

void trace(void){
    char ligne[LM+1];
    int i;

    for (i = 0;i < NP;i++){
        printf("Donner un point (1 caractère) et deux coordonées : ");
//        gets(ligne);
        fgets(ligne, sizeof(ligne), stdin);
        sscanf(ligne, "%c %d %d", &courbe[i].c, &courbe[i].x, &courbe[i].y);
    }

    affiche_courbe();
}

int main() {
    struct s_point s;

    s.c = 'B';
    s.x = 10;
    s.y = 12;

    affiche_point(s);
    affiche_point(oppose(s));
    reset(&s);
    affiche_point(s);
    printf("\n");
    trace();
}