#include "components.h"


bool starts_the_game() {
    for (int i = 0; i < width; i++) {field[0][i] = '\"'; field[height - 1][i] = '\"';}

    for (int i = 1; i < height - 1; i++) {
        field[i][0] = '\"';
        for (int j = 1; j < width - 1; j++)
            field[i][j] = ' ';
        field[i][width - 1] = '\"';}

    show_field();

    return false;
}

void show_field() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }

//    for (int j = 0; j < width; j++) {
//        printf("%c", field[1][j]);
//    }

    return ;
}