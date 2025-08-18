#include <stdio.h>
#include <stdlib.h>
#define HAUT 15
#define LARGE 8

struct piece {
    int x[4];
    int y[4];
    char type;
};

int fin(int tab[HAUT][LARGE]);
int update(int tab[HAUT][LARGE], char commande);
int affichage(int tab[HAUT][LARGE], struct piece piece);
char demande_tour(void);
struct piece new_piece(struct piece piece);
int possible(int tab[HAUT][LARGE], char commande, struct piece piece);
int test_piece(struct piece piece);
struct piece tourne(struct piece piece);
struct piece gauche(struct piece piece);
struct piece droite(struct piece piece);
struct piece descend(struct piece piece);
struct piece initialisation(struct piece piece);

int main(){
    int zone [HAUT][LARGE] = { 0 };
    char rep;
    int score = 0;

    srand( time( NULL ) ); 
    
    do {
        rep = demande_tour();
        score += update(zone, rep);
    } while (fin == 0);

    printf("=========================================================\n");
    printf("Bravo : vous avez obtenu %d point(s) !!!\n");

    return 1;
}

int affichage(int tab[HAUT][LARGE], struct piece piece){
    int i;

    for (i = 0;i < HAUT;i++){
        int j;
        for (j = 0;j < LARGE;j++){
            switch(tab[i][j]){
                case 0 : if (((piece.x[0] == i) && (piece.y[0] == j)) || ((piece.x[1] == i) && (piece.y[1] == j)) || ((piece.x[2] == i) && (piece.y[2] == j)) || ((piece.x[3] == i) && (piece.y[3] == j))){
                             printf("#");
                         } else {
                             printf(".");
                         }
                         break;
                case 1 : printf("#");
                         break;
                default : printf(".");
                          break;
            }
        }
        printf("/n");
    }

    return 1;
}

int update (int tab[HAUT][LARGE], char commande){
    static struct piece piece = { 0 };
    
    if (test_piece(piece) == 1){
        piece = new_piece(piece);
    }
    if (possible(tab,commande,piece) == 1){
        switch(commande){
            case 'z' : piece = tourne(piece);
                       break;
            case 'q' : piece = gauche(piece);
                       break;
            case 'd' : piece = droite(piece);
                       break;
            case 's' : piece = descend(piece);
                       break;
            default : return -1;
        }
    }

    if (possible(tab,'s',piece)){
        piece = descend(piece);
    } else {
        int i;
        for (i = 0;i < 4;i++){
            int j;
            for(j = 0;j < 4;j++){
                tab[piece.x[i]][piece.y[j]] = 1;
            }
        }
        piece = initialisation(piece);
    }
    affichage(tab, piece);

    return 1;
}

struct piece new_piece(struct piece piece){
    int type;

    type = rand() % 5;

    switch(type){
        case 0 : int i;
                 piece.type = 'b';                              // Barre de 4 carreaux (4 x 1)
                 for (i = 0;i < 4;i++){
                    piece.y[i] = 0;
                    piece.x[i] = LARGE / 2 - i / 2;
                 }
                 break;
        case 1 : piece.type = 't';                              // T de 4 carreaux (3 + 1)
                 piece.x[0] = LARGE / 2;
                 piece.x[1] = LARGE / 2 - 1;
                 piece.x[2] = LARGE / 2;
                 piece.x[3] = LARGE / 2 + 1;
                 piece.y[0] = 0;
                 piece.y[1] = 1;
                 piece.y[2] = 1;
                 piece.y[3] = 1;
                 break;
        case 2 : piece.type = 'z';                               // Zigzag de 4 carreaux (2 + 2)
                 piece.x[0] = LARGE / 2;
                 piece.x[1] = LARGE / 2;
                 piece.x[2] = LARGE / 2 + 1;
                 piece.x[3] = LARGE / 2 + 1;
                 piece.y[0] = 0;
                 piece.y[1] = 1;
                 piece.y[2] = 1;
                 piece.y[3] = 2;
                 break;
        case 3 : piece.type = 'c';                              // Carré de 4 carreaux (2 x 2)
                 piece.x[0] = LARGE / 2;
                 piece.x[1] = LARGE / 2;
                 piece.x[2] = LARGE / 2 + 1;
                 piece.x[3] = LARGE / 2 + 1;
                 piece.y[0] = 0;
                 piece.y[1] = 0;
                 piece.y[2] = 1;
                 piece.y[3] = 1;
                 break;
        case 4 : piece.type = 'l';                              // L de 4 carreaux (3 + 1)
                 piece.x[0] = LARGE / 2;
                 piece.x[1] = LARGE / 2;
                 piece.x[2] = LARGE / 2;
                 piece.x[3] = LARGE / 2 + 1;
                 piece.y[0] = 0;
                 piece.y[1] = 1;
                 piece.y[2] = 2;
                 piece.y[3] = 2;
                 break;
        default : new_piece(piece);
                  break;
    }

    return piece;
}

int test_piece(struct piece piece){
    int i;
    int oui;

    for(i = oui = 0;i < 4;i++){
        if ((piece.x[i] == 0) && (piece.y[i] == 0)){
            oui += 1;
        }
    }

    if (oui == 4) return 1;
    return 0;
}

struct piece initialisation(struct piece piece){
    int i;
    
    for (i = 0;i < 4;i++){
        piece.x[i] = 0;
        piece.y[i] = 0;
    }
    
    return piece;
}

struct piece tourne(struct piece piece){
    switch(piece.type){
        case 'b' : if (piece.x[0] == piece.x[1]){      // Si la barre est à l'horizontale
                       piece.x[0] -= 1;
                       piece.x[2] += 1;
                       piece.x[3] += 2;
                       piece.y[0] = piece.y[2] = piece.y[3] = piece.y[1];
                   } else {                            // Si la barre est à la verticale
                       piece.x[0] = piece.x[2] = piece.x[3] = piece.x[1];
                       piece.y[0] -= 1;
                       piece.y[2] += 1;
                       piece.y[3] += 2;
                   }
                   break;
        case 't' : if (piece.x[0] == piece.x[1]){  // Si le T est vers la bas ou vers le haut
                       if (piece.x[0] == piece.x[1] - 1){  // Si le T est vers la bas
                           piece.x[0] += 1;
                           piece.x[2] -= 1;
                           piece.x[3] -= 1;
                           piece.y[0] -= 1;
                           piece.y[2] += 1;
                           piece.y[3] -= 1;
                       } else {                            // Si le T est vers le haut
                           piece.x[0] -= 1;
                           piece.x[2] += 1;
                           piece.x[3] += 1;
                           piece.y[0] += 1;
                           piece.y[2] -= 1;
                           piece.y[3] += 1;
                       }
                   } else if (piece.y[0] == piece.y[1] - 1){ // Si le T est vers la gauche 
                       piece.x[0] += 1;
                       piece.x[2] -= 1;
                       piece.x[3] += 1;
                       piece.y[0] += 1;
                       piece.y[2] -= 1;
                       piece.y[3] -= 1;
                   } else {                                  // Si le T est vers la gauche
                       piece.x[0] -= 1;
                       piece.x[2] += 1;
                       piece.x[3] -= 1;
                       piece.y[0] -= 1;
                       piece.y[2] += 1;
                       piece.y[3] += 1;
                   }
                   break;
        case 'z' : if (piece.x[0] == piece.x[1]){ // Si le Z est horizontal
                       piece.x[0] -= 1;
                       piece.x[1] -= 2;
                       piece.x[2] += 1;
                       piece.y[1] -= 1;
                       piece.y[3] -= 1;
                   } else {                       // Si le Z est vertical
                       piece.x[0] += 1;
                       piece.x[1] += 2;
                       piece.x[2] -= 1;
                       piece.y[1] += 1;
                       piece.y[3] += 1;
                   }
                   break;
        case 'c' : break;
        case 'l' : if (piece.x[0] == piece.x[1]){   //Si le L est allongé sur le "dos" ou sur le "ventre" (petite pointe en haut ou en bas)
                       if (piece.x[0] == piece.x[1] - 1){ //Si le L est allongé sur le "dos"
                           piece.x[0] += 1;
                           piece.x[2] -= 1;
                           piece.y[0] -= 1;
                           piece.y[2] += 1;
                           piece.y[3] += 2;
                       } else {                            // Si le L est allongé sur le "ventre"
                           piece.x[0] -= 1;
                           piece.x[2] += 1;
                           piece.y[0] += 1;
                           piece.y[2] -= 1;
                           piece.y[3] -= 2;
                       }
                   } else if (piece.y[0] == piece.y[1] - 1){ // Si le L est à l'endroit
                       piece.x[0] += 1;
                       piece.x[2] -= 1;
                       piece.x[3] -= 2;
                       piece.y[0] += 1;
                       piece.y[2] -= 1;
                   } else {                                  // Si le L est à l'envers
                       piece.x[0] -= 1;
                       piece.x[2] += 1;
                       piece.x[3] += 2;
                       piece.y[0] -= 1;
                       piece.y[2] += 1;
                   }
                   break;
        default : break;
    }

    return piece;
}

struct piece gauche(struct piece piece){
    int i;
    for (i = 0;i < 4;i++){
        piece.x[i] -= 1;
    }

    return piece;
}

struct piece droite(struct piece piece){
    int i;
    for (i = 0;i < 4;i++){
        piece.x[i] += 1;
    }

    return piece;
}

struct piece descend(struct piece piece){
    int i;
    for (i = 0;i < 4;i++){
        piece.y[i] += 1;
    }

    return piece;
}

int possible (int tab[HAUT][LARGE], char commande, struct piece piece){
    switch (commande){
        case 'z' : switch(piece.type){
                       case 'b' : if (piece.x[0] == piece.x[1]){ // Barre horizontale vers position verticale puis l'inverse
                                      int oui;
                                      if ((tab[piece.x[1]][piece.y[1]] == 0) && (tab[piece.x[1]][piece.y[2]] == 0) && (tab[piece.x[1]][piece.y[3] == 0])){
                                          return 1;
                                      }
                                  } else if ((tab[piece.x[1]][piece.y[1]] == 0) && (tab[piece.x[1]][piece.x[2]] == 0) && (tab[piece.x[1]][piece.x[3]] == 0)) {
                                      return 1;
                                  }
                                  break;
                       case 't' : if (piece.x[0] == piece.x[1]){ // T vers bas ou haut
                                      if (piece.x[0] == piece.x[1] - 1){ // T vers le bas
                                          if ((tab[piece.x[1]][piece.y[1] - 1] == 0)){
                                              return 1;
                                          }
                                      } else {                               // T vers le haut
                                           if ((tab[piece.x[1]][piece.y[1] + 1] == 0)){
                                               return 1;
                                           }
                                      }
                                  } else if (piece.y[0] == piece.y[1] + 1){ // T vers la gauche
                                      if (tab[piece.x[1] + 1][piece.y[1]] == 0){
                                        return 1;
                                      }
                                  } else {                                  // T vers la droite
                                      if (tab[piece.x[1] - 1][piece.y[1]] == 0){
                                          return 1;
                                      }
                                  }
                                  break;
                       case 'z' : if (piece.x[0] == piece.x[1]){ // Z horizontal
                                      if ((tab[piece.x[1]][piece.y[1] - 1] == 0) && (tab[piece.x[0]][piece.y[2]] == 0)){
                                          return 1;
                                      }
                                  } else {                       // Z vertical
                                      if ((tab[piece.x[0]][piece.y[3]] == 0) && (tab[piece.x[0] - 1][piece.y[3]] == 0)){
                                          return 1;
                                      }
                                  }
                                  break;
                       case 'c' : return 1;
                       case 'l' : if ()
        }
    }
}