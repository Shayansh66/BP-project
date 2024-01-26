#include "components.h"

char field[height][width];

void close_app();


int main() {
    atexit(close_app);
    bool app_is_open = true;

    while (app_is_open) {
        switch (menu()) {
            case 1:
                app_is_open = starts_the_game();
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }


    getchar();

    return 0;
}


void close_app() {
//    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\tsee you next time :)");
    printf("\n\n\n\n\n\n\n");
}