#include "components.h"


bool spawn_enemy(int phase) {
    temp_random_number = number_maker(temp_random_number, phase);
    switch (spawn_list[temp_random_number % 4 + 4]) {
        case 1:
            if (num_of_mines < spawn_limit[1]) {
                num_of_mines == 0 ? mine_list = create_mine(temp_random_number % 96 + 2)
                                  : append_mine(mine_list, create_mine(temp_random_number % 96 + 2));
                return true;
            }
            break;
/*        case 2:
            if (num_of_bombers < spawn_limit[2])

            break;
        case 3:
            if (num_of_cargoes < spawn_limit[3]) break;
            num_of_cargoes == 0 ? cargo_list = create_cargo(temp_random_number % 84 + 8)
                              : append_cargo(cargo_list, create_cargo(temp_random_number % 84 + 8));
            break;
        case 4:
            if (num_of_fighters < spawn_limit[4]) break;
            num_of_fighters == 0 ? fighter_list = create_fighter(temp_random_number % 86 + 7)
                                : append_fighter(fighter_list, create_fighter(temp_random_number % 86 + 7));
            break;*/
    }
    return false;
}