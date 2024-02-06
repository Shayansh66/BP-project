#ifndef THE_PROJECT_COMPONENTS_H
#define THE_PROJECT_COMPONENTS_H

#include <ctype.h>
#include <math.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define height 38
#define width 100
#define maximum_amount 15
#define easy 1
#define medium 2
#define hard 3
#define minimumHealth 10
#define maX(a, b) a < b ? b : a
#define miN(a, b) a > b ? b : a

extern char places[width][maximum_amount][7];
extern char field[height][width];
extern int border_of_field_changes[height][2];
extern int item_size[8][2];
extern int max_Y, max_X, console_size_Y, console_size_X;
extern int difficulty, level;
extern int num_of_mines, num_of_bombers, num_of_cargoes, num_of_fighters, num_of_bombs, num_of_V_shoots, num_of__shoots;
extern int total_mines, total_bombers, total_cargoes, total_fighters, total_bombs, total_V_shoots, total__shoots;
extern WINDOW * output_field;
extern char game_time[9], game_date[12];
extern int seed, temp_random_number;
extern time_t Time;
extern int temp_int;
extern int spawn_list[16];
extern int spawn_limit[7];
extern char tempString[width];

typedef struct {
    int y;
    int x;
} the_location;

typedef struct {
    the_location tlc;
    the_location brc;
} the_border;

typedef struct common_attributes{
    char id[6];
    the_location loc;
    the_border main_border;
    unsigned int damage;    // or death damage
    unsigned int health;
    char ** shape;
    int * shape_back_space;
} common;

typedef struct {
    common * commons;
    the_border sub_border_1;
    the_border sub_border_2;
} player;

typedef struct inputs{
    char input_key;
    int time;
    struct inputs * next;
} user_input;

typedef struct mines {
    common * commons;
    struct mines * next;
} mine;

typedef struct bombers {
    common * commons;
    bool direction;
    struct bombers * next;
} bomber;

typedef struct cargoes {
    common * commons;
    the_border sub_border_1;
    the_border sub_border_2;
    struct cargoes * next;
} cargo;

typedef struct fighters {
    common * commons;
    the_border sub_border_1;
    the_border sub_border_2;
    struct fighters * next;
} fighter;

typedef struct bombs {
    common * commons;
    struct bombs * next;
} bomb;

typedef struct V_shoots {
    common * commons;
    struct V_shoots * next;
} V_shoot;

typedef struct _shoots {
    common * commons;
    struct _shoots * next;
} _shoot;

extern player * spaceship;
extern mine * mine_list;
extern bomber * bomber_list;
extern cargo * cargo_list;
extern fighter * fighter_list;
extern bomb * bomb_list;
extern V_shoot * V_shoot_list;
extern _shoot * _shoot_list;

int menu();
void show_menu(WINDOW *);

void starts_the_game();
void show_field();
void initialize_spaceship();

int select_level();
void show_levels(WINDOW *);

int generate_main_seed();
int number_maker(int, int);

int detect_entered_key(int);
int take_input_key();

bool spawn_enemy(int);

void move_items();
void player_move();
void move_mines();
void move_cargoes();
void clean_item(common *, int);
void clean_border(common * data);
void matrix_move_vertical(common *, int);
void matrix_move_horizontal(common *, int);
void put_item(common *, int);

player * create_spaceship ();
user_input * create_input(int, char);
void append_user_input(user_input *, user_input *);
mine * create_mine(int);
bomber * create_bomber_left();
cargo * create_cargo(int);
fighter * create_fighter(int);
bomb * creat_bomb(int, int);
V_shoot * creat_V_shoot(int, int);
_shoot * creat__shoot(int, int);
void append_mine(mine *, mine *);
void append_bomber(bomber *, bomber *);
void append_cargo(cargo *, cargo *);
void append_fighter(fighter *, fighter *);
void append_bomb(bomb *, bomb *);
void append_V_shoot(V_shoot *, V_shoot *);
void append__shoot(_shoot *, _shoot *);
void delete_mine_from_start(mine *);
void delete_bomber_from_start(bomber *);
void delete_cargo_from_start(cargo *);
void delete_fighter_from_start(fighter *);
void delete_bomb_from_start(bomb *);
void delete_V_shoot_from_start(V_shoot *);
void delete__shoot_from_start(_shoot *);
void delete_mine_from_middle(mine *, int);
void delete_bomber_from_middle(bomber *, int);
void delete_cargo_from_middle(cargo *, int);
void delete_fighter_from_middle(fighter *, int);
void delete_bomb_from_middle(bomb *, int);
void delete_V_shoot_from_middle(V_shoot *, int);
void delete__shoot_from_middle(_shoot *, int);
void delete_mine_from_end(mine * list);
void delete_bomber_from_end(bomber * list);
void delete_cargo_from_end(cargo * list);
void delete_fighter_from_end(fighter * list);
void delete_bomb_from_end(bomb * list);
void delete_V_shoot_from_end(V_shoot * list);
void delete__shoot_from_end(_shoot * list);

void play_the_game();

#endif //THE_PROJECT_COMPONENTS_H