#ifndef THE_PROJECT_COMPONENTS_H
#define THE_PROJECT_COMPONENTS_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define height 20
#define width 30

extern char field[height][width];

int menu();

bool starts_the_game();
void show_field();

#endif //THE_PROJECT_COMPONENTS_H
