#include "components.h"


void move_items() {
    player_move();
    move_mines();
    move_cargoes();
}

void player_move() {
    char entered_key = (char) take_input_key(output_field);
    switch (entered_key) {
        case 'w':
            if (spaceship->commons->loc.y <= 5)
                return;
            clean_border(spaceship->commons);
            spaceship->commons->loc.y--;
            spaceship->commons->main_border.tlc.y--;
            spaceship->commons->main_border.brc.y--;
            put_item(spaceship->commons, item_size[0][0]);
            break;

        case 's':
            if (spaceship->commons->loc.y >= height - 7)
                return;
            clean_border(spaceship->commons);
            spaceship->commons->loc.y++;
            spaceship->commons->main_border.tlc.y++;
            spaceship->commons->main_border.brc.y++;
            put_item(spaceship->commons, item_size[0][0]);
            break;

        case 'a':
            if (spaceship->commons->loc.x <= 7)
                return;
            clean_border(spaceship->commons);
            spaceship->commons->loc.x--;
            spaceship->commons->main_border.tlc.x--;
            spaceship->commons->main_border.brc.x--;
            put_item(spaceship->commons, item_size[0][0]);
            break;

        case 'd':
            if (spaceship->commons->loc.x >= width - 8)
                return;
            clean_border(spaceship->commons);
            spaceship->commons->loc.x++;
            spaceship->commons->main_border.tlc.x++;
            spaceship->commons->main_border.brc.x++;
            put_item(spaceship->commons, item_size[0][0]);
            break;

        default:
            return ;
    }
    put_item(spaceship->commons, item_size[0][0]);
}

void move_mines() {
    mine * temp_list = mine_list;
    for (int i = 0; i < num_of_mines; i++) {
        clean_border(temp_list->commons);
        temp_list->commons->loc.y++;
        temp_list->commons->main_border.tlc.y++;
        temp_list->commons->main_border.brc.y++;
        if (temp_list->commons->loc.y >= height - 1 - temp_list->commons->main_border.tlc.y) {
            if (i == 0)
                delete_mine_from_start(temp_list);
            else if (i == num_of_cargoes - 1)
                delete_mine_from_end(temp_list);
            else
                delete_mine_from_middle(temp_list, i);
            continue;
        }

        put_item(temp_list->commons, item_size[1][0]);
        temp_list = temp_list->next;
    }
}

void move_cargoes() {
    cargo * temp_list = cargo_list;
    for (int i = 0; i < num_of_cargoes; i++) {
        clean_border(temp_list->commons);
        temp_list->commons->loc.y++;
        temp_list->commons->main_border.tlc.y++;
        temp_list->commons->main_border.brc.y++;
        if (temp_list->commons->loc.y >= height - 1 - temp_list->commons->main_border.tlc.y) {
            if (i == 0)
                delete_cargo_from_start(temp_list);
            else if (i == num_of_cargoes - 1)
                delete_cargo_from_end(temp_list);
            else
                delete_cargo_from_middle(temp_list, i);
            continue;
        }

        put_item(temp_list->commons, item_size[1][0]);
        temp_list = temp_list->next;
    }
}

void clean_item(common * data, int item_height) {
    for (int i = 0; i < item_height; i++) {
        sprintf(tempString, "%*c", data->shape_back_space[i] * 2 + 1, ' ');
        strncpy(field[data->main_border.tlc.y + i], tempString, data->shape_back_space[i] * 2 + 1);
        mvwprintw(output_field, data->main_border.tlc.y + i, data->loc.x - data->shape_back_space[i],
                  "%*c", item_size[0][1], ' ');
    }
}

void clean_border(common * data) {
    for (int i = 0; i < item_size[0][0]; i++) {
        if (height - 2 < data->main_border.tlc.y + i || data->main_border.tlc.y + i < 1) {continue;}
        mvwprintw(output_field, data->main_border.tlc.y + i, data->loc.x - data->shape_back_space[i], "%*c", data->shape_back_space[i] * 2 + 1, ' ');
    }
}

void matrix_move_vertical(common * data, int move) {
    data->loc.y += move;
    data->main_border.tlc.y += move;
    data->main_border.brc.y += move;
}

void matrix_move_horizontal(common * data, int move) {
    data->loc.x += move;
    data->main_border.tlc.x += move;
    data->main_border.brc.x += move;
}

void put_item(common * data, int item_height) {
    for (int i = 0; i < item_height; i++) {
        if (height - 2 < data->main_border.tlc.y + i || data->main_border.tlc.y + i < 1) {continue;}

        mvwprintw(output_field, data->main_border.tlc.y + i,
                  data->loc.x - data->shape_back_space[i],
                  "%s", data->shape[i]);

/*        strncpy(field[data->main_border.tlc.x + i] + data->loc.x - data->shape_back_space[i], data->shape[i],
                data->shape_back_space[i] * 2 + 1);
        if (border_of_field_changes[data->main_border.tlc.x + i][1] == 0) {
            border_of_field_changes[data->main_border.tlc.x + i][1] = data->loc.x + data->shape_back_space[i];
            border_of_field_changes[data->main_border.tlc.x + i][0] = data->loc.x - data->shape_back_space[i];
        }
        else {
            border_of_field_changes[data->main_border.tlc.x + i][1] =maX
                    (border_of_field_changes[data->main_border.tlc.x + i][1], data->loc.x + data->shape_back_space[i]);
            border_of_field_changes[data->main_border.tlc.x + i][0] =miN
                    (border_of_field_changes[data->main_border.tlc.x + i][0], data->loc.x - data->shape_back_space[i]);
        }*/
    }
}