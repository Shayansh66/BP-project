#include "components.h"

char field[height][width];

void close_app();


int main() {
    atexit(close_app);

    switch (menu())
    {
        case 1:
            starts_the_game();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            exit(0);
            break;
    }

    getchar();


    return 0;
}


void close_app() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\tsee you next time :)");
    printf("\n\n\n\n\n\n\n");
}