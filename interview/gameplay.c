#include "components.h"

void play_the_game() {
    strcpy(game_time, __TIME__);
    strcpy(game_date, __DATE__);
    Time = time(NULL);
    temp_random_number = seed = generate_main_seed();

    output_field = newwin(height, width, 2, 3);
    getmaxyx(output_field, console_size_Y, console_size_X);
    wborder(output_field, 'I', 'I', '\"', '\"', '\"', '\"', '\"', '\"');
    keypad(output_field, true);
    nodelay(output_field, true);
    refresh();

    initialize_spaceship();
    show_field();
    mvprintw(height + 3, console_size_X / 2 - 10, "Press WASD keys to move...");

//    int entered_key;
    for (int counter = 0; counter < 70; counter++) {
        if (counter >= 6) { spawn_enemy(counter); }

//        shoot();

        move_items();

//        check_collide(); or break when player die

        show_field();
        napms(75);
    }

}

void initialize_spaceship() {
    spaceship = create_spaceship();
    put_item(spaceship->commons, item_size[0][0]);
}

void show_field() {
    for (int i = 0; i < height; i++) {
        if (border_of_field_changes[i][1] != 0) {           // it has some changes

            // split the changed part of each row
            strncpy(tempString, field[i] + border_of_field_changes[i][0],
                    border_of_field_changes[i][1] - border_of_field_changes[i][0]);

            mvwprintw(output_field, i, border_of_field_changes[i][0], "%s", tempString);
        }
    }
    wrefresh(output_field);
}

void fill_spawn_info() {
    switch (level) {
        case easy:
            spawn_list[0] = 3;
            spawn_list[1] = 3;
            spawn_list[2] = 3;
            spawn_list[3] = 3;
            spawn_list[4] = 1;
            spawn_list[5] = 1;
            spawn_list[6] = 1;
            spawn_list[7] = 1;
            spawn_list[8] = 4;
            spawn_list[9] = 4;
            spawn_list[10] = 4;
            spawn_list[11] = 4;
            spawn_list[12] = 2;
            spawn_list[13] = 2;
            spawn_list[14] = 2;
            spawn_list[15] = 2;

            spawn_limit[1] = 4;
            spawn_limit[2] = 1;
            spawn_limit[3] = 2;
            spawn_limit[4] = 3;
            break;
        case medium:
            spawn_list[0] = 2;
            spawn_list[1] = 2;
            spawn_list[2] = 2;
            spawn_list[3] = 2;
            spawn_list[4] = 4;
            spawn_list[5] = 4;
            spawn_list[6] = 4;
            spawn_list[7] = 4;
            spawn_list[8] = 1;
            spawn_list[9] = 1;
            spawn_list[10] = 1;
            spawn_list[11] = 1;
            spawn_list[12] = 1;
            spawn_list[13] = 1;
            spawn_list[14] = 3;
            spawn_list[15] = 3;

            spawn_limit[1] = 6;
            spawn_limit[2] = 3;
            spawn_limit[3] = 3;
            spawn_limit[4] = 4;
            break;
        case hard:
            spawn_list[0] = 2;
            spawn_list[1] = 2;
            spawn_list[2] = 2;
            spawn_list[3] = 2;
            spawn_list[4] = 2;
            spawn_list[5] = 4;
            spawn_list[6] = 4;
            spawn_list[7] = 4;
            spawn_list[8] = 4;
            spawn_list[9] = 4;
            spawn_list[10] = 4;
            spawn_list[11] = 1;
            spawn_list[12] = 1;
            spawn_list[13] = 1;
            spawn_list[14] = 1;
            spawn_list[15] = 3;

            spawn_limit[1] = 8;
            spawn_limit[2] = 6;
            spawn_limit[3] = 1;
            spawn_limit[4] = 5;
            break;
    }
}