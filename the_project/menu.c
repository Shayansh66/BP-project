#include "components.h"


int menu() {
    char input;
    int selected = 1;
    printf("\n\n\n\n\n");
    printf("\t\t _________________\n");
    printf("\t\t|                 |\n");
    printf("\t\t|     1- Play     |\n");
    printf("\t\t|     2- Level    |\n");
    printf("\t\t|     3- Logs     |\n");
    printf("\t\t|     4- Exit     |\n");
    printf("\t\t|                 |\n");
    printf("\t\t|_________________|\n");


    while (1) {
        input = getchar();
        getchar();
        if (isdigit(input)) {
            if ('1' <= input && input <= '4') {
                selected = input - 48;
                system("cls");
                return selected;
            }
        }
        else if (isalpha(input)) {
            switch (input) {
                case 'w':
                case 'W':
                    if (selected > 1)
                        selected--;
                    break;
                case 's':
                case 'S':
                    if (selected < 4)
                        selected++;
                    break;
            }
        }
        else if (input == '\n') {
            system("cls");
            return selected;
        }
    }
}