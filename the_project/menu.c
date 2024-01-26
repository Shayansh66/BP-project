#include "components.h"


int menu() {
    int input;
    printf("\n\n\n\n\n");
    printf("\t\t _________________\n");
    printf("\t\t|                 |\n");
    printf("\t\t|     1- Play     |\n");
    printf("\t\t|     2- Level    |\n");
    printf("\t\t|     3- Logs     |\n");
    printf("\t\t|     4- Exit     |\n");
    printf("\t\t|                 |\n");
    printf("\t\t|_________________|\n");

    input = getchar();


    system("cls");
    return input - 48;
}