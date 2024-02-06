#include "components.h"


int menu() {
    int input_character;
    bool arrow_key_input = false;
    int selected = 1;

    WINDOW * menu_win = newwin(8, 23, max_Y/2 - 6, max_X/2 - 11);
    keypad(menu_win, true);
    show_menu(menu_win);

    while (true) {
        input_character = wgetch(menu_win);
        input_character = detect_entered_key(input_character);

        if (isdigit(input_character)) {
            if ('1' <= input_character && input_character <= '3') {
                selected = input_character - 48;
                break;          // break the while
            }
        }

        else if (input_character == '\n')
            break;          // break the while

        else if (input_character == 27) {       // Esc key
            selected = level;                   // the last chosen item
            break;          // break the while
        }

        else {                      // character or alphabet

            if (arrow_key_input == false && (input_character == 'w' || input_character == 's')) {
                arrow_key_input = true;
                selected = 1;
                mvwprintw(menu_win, 1 + selected, 16, "<-");
            }

            else
                switch (input_character) {
                    case 'w':
                        if (selected > 1) {
                            mvwprintw(menu_win, 1 + selected, 16, "  ");
                            selected--;
                            mvwprintw(menu_win, 1 + selected, 16, "<-");
                        }
                        break;
                    case 's':
                        if (selected < 3) {
                            mvwprintw(menu_win, 1 + selected, 16, "  ");
                            selected++;
                            mvwprintw(menu_win, 1 + selected, 16, "<-");
                        }
                        break;
                }

            refresh();
        }
    }

    napms(90);
    return selected;
}

void show_menu(WINDOW * menu_win) {
    clear();

    refresh();
    box(menu_win, 0, 0);


    mvwprintw(menu_win, 2, 7, "1- Play");
    mvwprintw(menu_win, 3, 7, "2- Level");
    mvwprintw(menu_win, 4, 7, "3- Exit");
    wrefresh(menu_win);
    mvprintw(max_Y/2 - 7, max_X/2 - 11, "Level : %s", level == easy ? "Easy" : level == medium ? "Medium" : "Hard");
    refresh();
};

/*
    int input_character;
    bool arrow_key_input = false;
    int selected = 1;

    WINDOW * menu_win = newwin(10, 21, max_Y/2 - 2, max_X/2 - 10);
    keypad(menu_win, true);
    refresh();
    show_menu(menu_win);


    while (true) {
        input_character = wgetch(menu_win);
        input_character = detect_entered_key(input_character);

        if (isdigit(input_character)) {
            if ('1' <= input_character && input_character <= '3') {
                selected = input_character - 48;
                break;          // break the while
            }
        }

        else if (input_character == '\n')
            break;          // break the while

        else {                      // character or alphabet

            if (arrow_key_input == false && (input_character == 'w' || input_character == 's')) {
                arrow_key_input = true;
                selected = 1;
                mvwprintw(menu_win, 1 + selected, 22, "<-");
            }

            else
                switch (input_character) {
                    case 'w':
                        if (selected > 1) {
                            mvwprintw(menu_win, 1 + selected, 22, "  ");
                            selected--;
                            mvwprintw(menu_win, 1 + selected, 22, "<-");
                        }
                        break;
                    case 's':
                        if (selected < 3) {
                            mvwprintw(menu_win, 1 + selected, 22, "  ");
                            selected++;
                            mvwprintw(menu_win, 1 + selected, 22, "<-");
                        }
                        break;
                }

            wrefresh(menu_win);
        }

//        if (isdigit(input_character)) {
//            if ('1' <= input_character && input_character <= '4') {
//                selected = input_character - 48;
//                break;          // break the while
//            }
//        }
//
//        else if (isalpha(input_character)) {
//            // normalize input
//            input_character = tolower(input_character);
//
//            // the first arrow key press, correct key press
//            if (arrow_key_input == false && (input_character == 'w' || input_character == 's')) {
//                arrow_key_input = true;
//                selected = 1;
//                mvprintw(6 + selected, 31, "<-");
//            }
//
//            else
//                switch (input_character) {
//                    case 'w':
//                        if (selected > 1) {
//                            mvprintw(6 + selected, 31, "  ");
//                            selected--;
//                            mvprintw(6 + selected, 31, "<-");
//                        }
//                        break;
//                    case 's':
//                        if (selected < 4) {
//                            mvprintw(6 + selected, 31, "  ");
//                            selected++;
//                            mvprintw(6 + selected, 31, "<-");
//                        }
//                        break;
//                }
//
//            refresh();
//        }
//
//        else if (input_character == '\n')
//            break;          // break the while
//
    }


    napms(90);
    return selected;
}

void show_menu(WINDOW * menu_win) {
    box(menu_win, 0, 0);
    clear();
    mvwprintw(menu_win, 3, 7, "1- Play");
    mvwprintw(menu_win, 4, 7, "2- Level");
    mvwprintw(menu_win, 5, 7, "3- Exit");
    wrefresh(menu_win);

//    move(5, 17);
//    printw("-------------------");
//    mvprintw(6, 16, "|                   |");
//    mvprintw(7, 16, "|     1- Play       |");
//    mvprintw(8, 16, "|     2- Level      |");
//    mvprintw(9, 16, "|     3- Logs       |");
//    mvprintw(10, 16, "|     4- Exit       |");
//    mvprintw(11, 16, "|                   |");
//    mvprintw(12, 16, "|___________________|");
//    wrefresh(menu_win);
}
*/
