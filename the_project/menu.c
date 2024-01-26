#include "components.h"


void starts_the_game() {
    for (int i = 0; i < width; i++) {field[0][i] = '\"'; field[height - 1][i] = '\"';}

    for (int i = 1; i < height - 1; i++) {field[i][0] = '\"'; field[i][width - 1] = '\"';}

    show_field();

}

void show_field() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", field[i][j]);
    }
    printf("\n");
}