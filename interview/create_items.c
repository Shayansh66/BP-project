#include "components.h"

char temp_string[7];

void complete_common_attributes(common * node, char * id, int _X, int _Y, unsigned int health, unsigned int damage,
                                int tlc_X, int tlc_Y, int brc_X, int brc_Y) {
    strcpy(node->id, id);
    node->loc.x = _X;
    node->loc.y = _Y;
    node->health = health;
    node->damage = damage;
    node->main_border.tlc.x = node->loc.x + tlc_X;
    node->main_border.tlc.y = node->loc.y+ tlc_Y;
    node->main_border.brc.x = node->loc.x+ brc_X;
    node->main_border.brc.y = node->loc.y+ brc_Y;
}

player * create_spaceship () {
    player * the_spaceship = (player *) calloc(1, sizeof(player));
    the_spaceship->commons = (common *) calloc(1, sizeof(common));
    the_spaceship->commons->shape = (char **) calloc(10, sizeof(char *));

    the_spaceship->commons->shape[0] = (char *) calloc(3, sizeof(char));
    the_spaceship->commons->shape[1] = (char *) calloc(5, sizeof(char));
    the_spaceship->commons->shape[2] = (char *) calloc(9, sizeof(char));
    the_spaceship->commons->shape[3] = (char *) calloc(11, sizeof(char));
    the_spaceship->commons->shape[4] = (char *) calloc(13, sizeof(char));
    the_spaceship->commons->shape[5] = (char *) calloc(13, sizeof(char));
    the_spaceship->commons->shape[6] = (char *) calloc(7, sizeof(char));
    the_spaceship->commons->shape[7] = (char *) calloc(5, sizeof(char));
    the_spaceship->commons->shape[8] = (char *) calloc(3, sizeof(char));
    the_spaceship->commons->shape[9] = (char *) calloc(3, sizeof(char));

    the_spaceship->commons->shape_back_space = (int *) calloc(10, sizeof(int));

    complete_common_attributes(the_spaceship->commons, "000001", console_size_X / 2, console_size_Y - 9,
                               easy ? 400 : 300, easy ? 80 : 65, -6, -4, +6, +5);

    the_spaceship->sub_border_1.tlc.x = the_spaceship->commons->loc.x - 3;
    the_spaceship->sub_border_1.tlc.y = the_spaceship->commons->loc.y - 4;
    the_spaceship->sub_border_1.brc.x = the_spaceship->commons->loc.x + 3;
    the_spaceship->sub_border_1.brc.y = the_spaceship->commons->loc.y + 5;

    the_spaceship->sub_border_2.tlc.x = the_spaceship->commons->loc.x - 6;
    the_spaceship->sub_border_2.tlc.y = the_spaceship->commons->loc.y - 1;
    the_spaceship->sub_border_2.brc.x = the_spaceship->commons->loc.x + 6;
    the_spaceship->sub_border_2.brc.y = the_spaceship->commons->loc.y + 1;


    strcpy(the_spaceship->commons->shape[0],      "_!_");
    strcpy(the_spaceship->commons->shape[1],     "/(!)\\");
    strcpy(the_spaceship->commons->shape[2],   "_|     |_");
    strcpy(the_spaceship->commons->shape[3],  "/ |*****| \\");
    strcpy(the_spaceship->commons->shape[4], "/  |-----|  \\");
    strcpy(the_spaceship->commons->shape[5], "|__|*****|__|");
    strcpy(the_spaceship->commons->shape[6],    "|_____|");
    strcpy(the_spaceship->commons->shape[7],     "\\000/");
    strcpy(the_spaceship->commons->shape[8],      "###");
    strcpy(the_spaceship->commons->shape[9],      "%%%");

    the_spaceship->commons->shape_back_space[0] = 1;
    the_spaceship->commons->shape_back_space[1] = 2;
    the_spaceship->commons->shape_back_space[2] = 4;
    the_spaceship->commons->shape_back_space[3] = 5;
    the_spaceship->commons->shape_back_space[4] = 6;
    the_spaceship->commons->shape_back_space[5] = 6;
    the_spaceship->commons->shape_back_space[6] = 3;
    the_spaceship->commons->shape_back_space[7] = 2;
    the_spaceship->commons->shape_back_space[8] = 1;
    the_spaceship->commons->shape_back_space[9] = 1;

    return the_spaceship;
}

user_input * create_input(int time, char character) {
    user_input * the_user_input = (user_input *) calloc(1, sizeof(user_input));

    the_user_input->time = time;
    the_user_input->input_key = character;
    the_user_input->next = NULL;

    return the_user_input;

}

void append_user_input(user_input * list, user_input * new_user_input) {
    user_input * the_list = list;
    while (the_list->next != NULL)
        the_list = the_list->next;

    the_list->next = new_user_input;
}

mine * create_mine(int _X) {
    mine * the_mine = (mine *) calloc(1, sizeof(mine));
    num_of_mines++;
    total_mines++;

    the_mine->commons = (common *) calloc(1, sizeof(common));
    the_mine->commons->shape = (char **) calloc(3, sizeof(char *));
    for (int i = 0; i < 3; i++)
        the_mine->commons->shape[i] = (char *) calloc(3, sizeof(char));
    the_mine->commons->shape_back_space = (int *) calloc(3, sizeof(int));

    sprintf(temp_string, "11%.4d", total_mines);
    complete_common_attributes(the_mine->commons, temp_string, _X, 0,
                               120, 280, -1, -1, +1, +1);

    strcpy(the_mine->commons->shape[0], "\\|/");
    strcpy(the_mine->commons->shape[1], "-@-");
    strcpy(the_mine->commons->shape[2], "/|\\");

    the_mine->commons->shape_back_space[0] = 1;
    the_mine->commons->shape_back_space[1] = 1;
    the_mine->commons->shape_back_space[2] = 1;

    the_mine->next = NULL;

    return the_mine;
}

bomber * create_bomber_left() {
    bomber * the_bomber = (bomber *) calloc(1, sizeof(bomber));
    num_of_bombers++;
    total_bombers++;

    the_bomber->commons = (common *) calloc(1, sizeof(common));
    the_bomber->commons->shape = (char **) calloc(4, sizeof(char *));
    for (int i = 0; i < 4; i++)
        the_bomber->commons->shape[i] = (char *) calloc(10, sizeof(char));
    the_bomber->commons->shape_back_space = (int *) calloc(4, sizeof(int));

    sprintf(temp_string, "12%.4d", total_bombers);
    complete_common_attributes(the_bomber->commons, temp_string, -1, 2, 165, 210,
                               -6, -3, +2, +0);

    strcpy(the_bomber->commons->shape[0],  "_______");
    strcpy(the_bomber->commons->shape[1], "#ooO|   \\");
    strcpy(the_bomber->commons->shape[2],  "---/  _ \\");
    strcpy(the_bomber->commons->shape[3],   "|___]U[/");

    the_bomber->commons->shape_back_space[0] = 6;
    the_bomber->commons->shape_back_space[1] = 7;
    the_bomber->commons->shape_back_space[2] = 6;
    the_bomber->commons->shape_back_space[3] = 5;

    the_bomber->next = NULL;

    return the_bomber;
}

cargo * create_cargo(int _X) {
    cargo * the_cargo = (cargo *) calloc(1, sizeof(cargo));
    num_of_cargoes++;
    total_cargoes++;

    the_cargo->commons = (common *) calloc(1, sizeof(common));
    the_cargo->commons->shape = (char **) calloc(18, sizeof(char *));
    for (int i = 0; i < 4; i++)
        the_cargo->commons->shape[i] = (char *) calloc((int) (20.5 - (abs(i - 5) + abs(16 - i)) / 2.0), sizeof(char));
    the_cargo->commons->shape_back_space = (int *) calloc(18, sizeof(int));

    sprintf(temp_string, "13%.4d", total_cargoes);
    complete_common_attributes(the_cargo->commons, temp_string, _X, -1, 400, 400,
                               -7, -14, +7, +2);

    the_cargo->sub_border_1.tlc.x = the_cargo->commons->loc.x - 7;
    the_cargo->sub_border_1.tlc.y = the_cargo->commons->loc.y - 10;
    the_cargo->sub_border_1.brc.x = the_cargo->commons->loc.x + 7;
    the_cargo->sub_border_1.brc.y = the_cargo->commons->loc.y + 2;

    the_cargo->sub_border_2.tlc.x = the_cargo->commons->loc.x - 3;
    the_cargo->sub_border_2.tlc.y = the_cargo->commons->loc.y - 12;
    the_cargo->sub_border_2.brc.x = the_cargo->commons->loc.x + 3;
    the_cargo->sub_border_2.brc.y = the_cargo->commons->loc.y - 11;

    strcpy(the_cargo->commons->shape[0],       "#####");
    strcpy(the_cargo->commons->shape[1],        "###");
    strcpy(the_cargo->commons->shape[2],         "#");
    strcpy(the_cargo->commons->shape[3],       "/---\\");
    strcpy(the_cargo->commons->shape[4],      "| *** |");
    strcpy(the_cargo->commons->shape[5],  "+--|| *** ||--+");
    strcpy(the_cargo->commons->shape[6],  "| .|_\\___/_|. |");
    strcpy(the_cargo->commons->shape[7],  "|.           .|");
    strcpy(the_cargo->commons->shape[8],  "|-\\_/-\\_/-\\_/-|");
    strcpy(the_cargo->commons->shape[9],  "|.        _  .|");
    strcpy(the_cargo->commons->shape[10],  "|        |%|  |");
    strcpy(the_cargo->commons->shape[11],  "| [o][o] |%|  |");
    strcpy(the_cargo->commons->shape[12],  "| [o][o] |%|  |");
    strcpy(the_cargo->commons->shape[13], "| [o]    |_|  |");
    strcpy(the_cargo->commons->shape[14], "|.           .|");
    strcpy(the_cargo->commons->shape[15], "|-\\_/-\\_/-\\_/-|");
    strcpy(the_cargo->commons->shape[16], "\\             /");
    strcpy(the_cargo->commons->shape[17],  "\\._________./");

    the_cargo->commons->shape_back_space[0] = 2;
    the_cargo->commons->shape_back_space[1] = 1;
    the_cargo->commons->shape_back_space[2] = 0;
    the_cargo->commons->shape_back_space[3] = 2;
    the_cargo->commons->shape_back_space[4] = 3;
    the_cargo->commons->shape_back_space[5] = 7;
    the_cargo->commons->shape_back_space[6] = 7;
    the_cargo->commons->shape_back_space[7] = 7;
    the_cargo->commons->shape_back_space[8] = 7;
    the_cargo->commons->shape_back_space[9] = 7;
    the_cargo->commons->shape_back_space[10] = 7;
    the_cargo->commons->shape_back_space[11] = 7;
    the_cargo->commons->shape_back_space[12] = 7;
    the_cargo->commons->shape_back_space[13] = 7;
    the_cargo->commons->shape_back_space[14] = 7;
    the_cargo->commons->shape_back_space[15] = 7;
    the_cargo->commons->shape_back_space[16] = 7;
    the_cargo->commons->shape_back_space[17] = 6;

    the_cargo->next = NULL;

    return the_cargo;
}

fighter * create_fighter(int _X) {
    fighter * the_fighter = (fighter *) calloc(1, sizeof(fighter));
    num_of_fighters++;
    total_fighters++;

    the_fighter->commons = (common *) calloc(1, sizeof(common));
    the_fighter->commons->shape = (char **) calloc(6, sizeof(char *));
    for (int i = 0; i < 6; i++)
        the_fighter->commons->shape[i] = (char *) calloc((15 - (i + abs(i - 2))), sizeof(char));
    the_fighter->commons->shape_back_space = (int *) calloc(6, sizeof(int));

    sprintf(temp_string, "14%.4d", total_mines);
    complete_common_attributes(the_fighter->commons, temp_string, _X, -2, 170, 190,
                               -6, -0, +6, +3);

    the_fighter->sub_border_1.tlc.x = the_fighter->commons->loc.x - 1;
    the_fighter->sub_border_1.tlc.y = the_fighter->commons->loc.y - 0;
    the_fighter->sub_border_1.brc.x = the_fighter->commons->loc.x + 1;
    the_fighter->sub_border_1.brc.y = the_fighter->commons->loc.y + 3;

    the_fighter->sub_border_2.tlc.x = the_fighter->commons->loc.x - 6;
    the_fighter->sub_border_2.tlc.y = the_fighter->commons->loc.y - 0;
    the_fighter->sub_border_2.brc.x = the_fighter->commons->loc.x - 6;
    the_fighter->sub_border_2.brc.y = the_fighter->commons->loc.y + 3;

    strcpy(the_fighter->commons->shape[0], ".         .");
    strcpy(the_fighter->commons->shape[1], "#    _    #");
    strcpy(the_fighter->commons->shape[2],"(O)==|_|==(O)");
    strcpy(the_fighter->commons->shape[3],     "| |");
    strcpy(the_fighter->commons->shape[4],     "| |");
    strcpy(the_fighter->commons->shape[5],      "V");

    the_fighter->commons->shape_back_space[0] = 5;
    the_fighter->commons->shape_back_space[1] = 5;
    the_fighter->commons->shape_back_space[2] = 6;
    the_fighter->commons->shape_back_space[3] = 1;
    the_fighter->commons->shape_back_space[4] = 1;
    the_fighter->commons->shape_back_space[5] = 0;

    the_fighter->next = NULL;

    return the_fighter;
}

bomb * creat_bomb(int _X, int _Y) {
    bomb * the_bomb = (bomb *) calloc(1, sizeof(bomb));
    num_of_bombs++;
    total_bombs++;

    the_bomb->commons = (common *) calloc(1, sizeof(common));
    the_bomb->commons->shape = (char **) calloc(2, sizeof(char *));
    for (int i = 0; i < 2; i++)
        the_bomb->commons->shape[i] = (char *) calloc(1, sizeof(char));
    the_bomb->commons->shape_back_space = (int *) calloc(2, sizeof(int));

    sprintf(temp_string, "15%.4d", total_mines);
    complete_common_attributes(the_bomb->commons, temp_string, _X, _Y, minimumHealth, 100,
                               -0, -1, +0, +0);

    the_bomb->next = NULL;

    return the_bomb;
}

V_shoot * creat_V_shoot(int _X, int _Y) {
    V_shoot * the_V_shoot = (V_shoot *) calloc(1, sizeof(V_shoot));
    num_of_V_shoots++;
    total_V_shoots++;

    the_V_shoot->commons = (common *) calloc(1, sizeof(common));
    the_V_shoot->commons->shape = (char **) calloc(1, sizeof(char *));
    for (int i = 0; i < 1; i++)
        the_V_shoot->commons->shape[i] = (char *) calloc(1, sizeof(char));
    the_V_shoot->commons->shape_back_space = (int *) calloc(1, sizeof(int));

    sprintf(temp_string, "16%.4d", total_mines);
    complete_common_attributes(the_V_shoot->commons, temp_string, _X, _Y, minimumHealth, 60,
                               -0, -0, +0, +0);

    the_V_shoot->next = NULL;

    return the_V_shoot;
}

_shoot * creat__shoot(int _X, int _Y) {
    _shoot * the__shoot = (_shoot *) calloc(1, sizeof(_shoot));
    num_of__shoots++;
    total__shoots++;

    the__shoot->commons = (common *) calloc(1, sizeof(common));
    the__shoot->commons->shape = (char **) calloc(1, sizeof(char *));
    for (int i = 0; i < 1; i++)
        the__shoot->commons->shape[i] = (char *) calloc(1, sizeof(char));
    the__shoot->commons->shape_back_space = (int *) calloc(1, sizeof(int));

    sprintf(temp_string, "11%.4d", total_mines);
    complete_common_attributes(the__shoot->commons, temp_string, _X, _Y, minimumHealth, level == easy ? 80 : 65,
                               -0, -0, +0, +0);

    the__shoot->next = NULL;

    return the__shoot;
}

void append_mine(mine * mines_list, mine * new_mine) {
    mine * the_list = mines_list;
    for (int i = 0; i < num_of_mines - 1; i++)
        the_list = the_list->next;

    the_list->next = new_mine;
}

void append_bomber(bomber * bombers_list, bomber * new_bomber) {
    bomber * the_list = bombers_list;
    for (int i = 0; i < num_of_bombers - 1; i++)
        the_list = the_list->next;

    the_list->next = new_bomber;
}

void append_cargo(cargo * cargos_list, cargo * new_cargo) {
    cargo * the_list = cargos_list;
    for (int i = 0; i < num_of_cargoes - 1; i++)
        the_list = the_list->next;

    the_list->next = new_cargo;
}

void append_fighter(fighter * fighters_list, fighter * new_fighter) {
    fighter * the_list = fighters_list;
    for (int i = 0; i < num_of_fighters - 1; i++)
        the_list = the_list->next;

    the_list->next = new_fighter;
}

void append_bomb(bomb * bombs_list, bomb * new_bomb) {
    bomb * the_list = bombs_list;
    for (int i = 0; i < num_of_bombs - 1; i++)
        the_list = the_list->next;

    the_list->next = new_bomb;
}

void append_V_shoot(V_shoot * V_shoots_list, V_shoot * new_V_shoot) {
    V_shoot * the_list = V_shoots_list;
    for (int i = 0; i < num_of_V_shoots - 1; i++)
        the_list = the_list->next;

    the_list->next = new_V_shoot;
}

void append__shoot(_shoot * _shoots_list, _shoot * new__shoot) {
    _shoot * the_list = _shoots_list;
    for (int i = 0; i < num_of__shoots - 1; i++)
        the_list = the_list->next;

    the_list->next = new__shoot;
}

void delete_mine_from_start(mine * list) {
    mine * delete = list;
    list = list->next;
    free(delete);
    num_of_mines--;
}

void delete_bomber_from_start(bomber * list) {
    bomber * delete = list;
    list = list->next;
    free(delete);
    num_of_bombers--;
}

void delete_cargo_from_start(cargo * list) {
    cargo * delete = list;
    list = list->next;
    free(delete);
    num_of_cargoes--;
}

void delete_fighter_from_start(fighter * list) {
    fighter * delete = list;
    list = list->next;
    free(delete);
    num_of_fighters--;
}

void delete_bomb_from_start(bomb * list) {
    bomb * delete = list;
    list = list->next;
    free(delete);
    num_of_bombs--;
}

void delete_V_shoot_from_start(V_shoot * list) {
    V_shoot * delete = list;
    list = list->next;
    free(delete);
    num_of_V_shoots--;
}

void delete__shoot_from_start(_shoot * list) {
    _shoot * delete = list;
    list = list->next;
    free(delete);
    num_of__shoots--;
}

void delete_mine_from_middle(mine * list, int number) {
    mine * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    mine * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of_mines--;
}

void delete_bomber_from_middle(bomber * list, int number) {
    bomber * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    bomber * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of_bombers--;
}

void delete_cargo_from_middle(cargo * list, int number) {
    cargo * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    cargo * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of_cargoes--;
}

void delete_fighter_from_middle(fighter * list, int number) {
    fighter * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    fighter * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
}

void delete_bomb_from_middle(bomb * list, int number) {
    bomb * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    bomb * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of_bombs--;
}

void delete_V_shoot_from_middle(V_shoot * list, int number) {
    V_shoot * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    V_shoot * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of_V_shoots--;
}

void delete__shoot_from_middle(_shoot * list, int number) {
    _shoot * the_list = list;
    for (int i = 0; i < number - 1; i++)
        the_list = the_list->next;

    _shoot * delete = the_list->next;
    the_list->next = the_list->next->next;
    free(delete);
    num_of__shoots--;
}

void delete_mine_from_end(mine * list) {
    mine * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    mine * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of_mines--;
}

void delete_bomber_from_end(bomber * list) {
    bomber * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    bomber * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of_bombers--;
}

void delete_cargo_from_end(cargo * list) {
    cargo * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    cargo * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of_cargoes--;
}

void delete_fighter_from_end(fighter * list) {
    fighter * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    fighter * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of_bombs--;
}

void delete_bomb_from_end(bomb * list) {
    bomb * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    bomb * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
}

void delete_V_shoot_from_end(V_shoot * list) {
    V_shoot * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    V_shoot * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of_V_shoots--;
}

void delete__shoot_from_end(_shoot * list) {
    _shoot * the_list = list;
    while (the_list->next->next != NULL)
        the_list = the_list->next;

    _shoot * delete = the_list->next;
    the_list->next = NULL;
    free(delete);
    num_of__shoots--;
}