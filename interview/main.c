#include "components.h"

char places[width][maximum_amount][7];
char field[height][width];
int border_of_field_changes[height][2];
char tempString[width];
int item_size[8][2] = {{10, 13}, {3, 3}, {4, 10}, {18, 15},
                       {6, 15}, {2, 1}, {1, 1}, {1, 1}};

int max_Y, max_X, console_size_Y, console_size_X;
int difficulty, level = 1;
int num_of_mines, num_of_bombers, num_of_cargoes, num_of_fighters, num_of_bombs, num_of_V_shoots, num_of__shoots;
int total_mines, total_bombers, total_cargoes, total_fighters, total_bombs, total_V_shoots, total__shoots;
char game_time[9], game_date[12];
player * spaceship;
mine * mine_list;
bomber * bomber_list;
cargo * cargo_list;
fighter * fighter_list;
bomb * bomb_list;
V_shoot * V_shoot_list;
_shoot * _shoot_list;
WINDOW * output_field;
time_t Time;
int seed, temp_random_number;
int temp_int;
int spawn_list[16];
int spawn_limit[7];     // [0] for total

void close_app();


int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    getmaxyx(stdscr, max_Y, max_X);
    keypad(stdscr, true);


    bool app_is_open = true;
    while (app_is_open) {
        switch (menu()) {
            case 1:
                play_the_game();
                break;
            case 2:
                level = select_level();
                break;
            case 3:
                app_is_open = false;
                break;
        }
    }

    clear();
    curs_set(1);
    close_app();
    endwin();
    return 0;
}


void close_app() {
    mvprintw(7, 8, "see you next time :)");
    mvprintw(20, 0, "Press any key to continue...");
    getch();
}