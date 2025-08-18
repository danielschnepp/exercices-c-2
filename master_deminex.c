#include <stdio.h>
#include <stdlib.h>

#define MAX_MINES 1

struct player {
    int x;
    int y;
    int dx;
    int dy;

};

struct player initialisation(int map[80][80]){
    int i;
    struct player player;
    for (i = 0;i < 80;i++){
        int j;
        for (j = 0;j < 80;j++){
            map[i][j] = 9;
        }
    }

    player.x = 0;
    player.y = 0;
    player.dx = 0;
    player.dy = 0;

    return player;
}

void generateur_map(int map[80][80], int level){
    int i;
    
    for (i = 0;i < (level * 10);i++){
        int j;
        int nb_mine = 0;
        for (j = 0;j < (level * 10);j++){
            if ((rand() % 2) && (nb_mine < (MAX_MINES * level)) && (i != 0) && (j != 0) && (i != (level * 10)) && (j != (level * 10))){
                map[i][j] = 1;
                nb_mine += 1;
            } else {
                map[i][j] = 0;
            }
            if ((i == (level * 10 - 1)) && (j == (level * 10 - 1))){
                map[i][j] = 0;
            }
        }
    }
    map[0][0] = 0;

    return;
}

int visible = 0;

void affichage_map(struct player player, int level, int map[80][80]){
    int i;
    for (i = 0;i < 10;i++){
        int j;
        for (j = 0;j < 10;j++){
            if ((i == player.y) && (j == player.x)){
                printf("P");
            } else if ((i == 0) && (j == 0)){
                printf("D");
            } else if ((i == (level * 10 - 1)) && (j == (level * 10 - 1))){
                printf("A");
            } else if ((visible) && (map[j][i])){
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int fin (struct player player, int level, int map[80][80]){
    if ((player.x == (level * 10 - 1)) && (player.y == (level * 10 - 1))){
        return 1;
    } else if (map[player.x][player.y] == 1){
        return -1;
    }
    return 0;
}

int nb_mine (struct player player, int map [80][80]){
    int mine = 0;
    int i;

    for (i = (player.x - 1);i < (player.x + 2);i++){
        int j;
        for (j = (player.y - 1);j < (player.y + 2);j++){
            if (map[i][j] == 1){
                mine += 1;
            }
        }
    }

    return mine;
}


struct player demande_tour (struct player player, int level, int map[80][80]){
    char rep;
    printf("Il y a %d mine(s) autour de vous.\n", nb_mine(player, map));
    printf("Donner une direction : ");
    scanf(" %c", &rep);

    switch (rep){
        case 'u' : player.dx = player.x;
                   player.dy = player.y - 1;
                   break;
        case 'd' : player.dx = player.x;
                   player.dy = player.y + 1;
                   break;
        case 'l' : player.dx = player.x - 1;
                   player.dy = player.y;
                   break;
        case 'r' : player.dx = player.x + 1;
                   player.dy = player.y;
                   break;
        case '?' : visible = ! visible;
                   break;
        default:
            break;
    }

    if ((player.dx < 0) || (player.dy < 0) || (player.dx > (level * 10 - 1)) || (player.dy > (level * 10 - 1))){
        demande_tour(player, level, map);
    }

    player.x = player.dx;
    player.y = player.dy;

    return player;
}

int main(){
    int level;
    int map[80][80];
    struct player player;
    
    for (level = 1;level < 11;level++){
        char rep;
        int i = 0;
        player = initialisation(map);
        generateur_map(map, level);
        while(1){
            affichage_map(player, level, map);
            switch (fin(player, level, map)){
                case 0 : player = demande_tour(player, level, map);
                         break;
                case 1 : printf("Victoire en %d mouvements !\n", i);
                case -1 : if (fin(player, level, map) == -1){
                              printf("Perdu...\n");
                          }
                          printf("Voulez-vous recommencer (o/n) ?");
                          scanf(" %c", &rep);
                          if (!((rep == 'o') || (rep == 'O') || (rep == 'y') || (rep == 'Y'))){
                             printf("Au revoir !\n");
                             return 1;
                          } else {
                             level = 1;
                             main();
                          }
                          break;
            }
            i++;
        }
    }
}