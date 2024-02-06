#include "components.h"



int select_level() {
    int input_character;
    bool arrow_key_input = false;
    int selected = 1;

    WINDOW * level_win = newwin(8, 24, max_Y/2 - 6, max_X/2 - 12);
    keypad(level_win, true);
    show_levels(level_win);

    while (true) {
        input_character = wgetch(level_win);
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
                mvwprintw(level_win, 1 + selected, 17, "<-");
            }

            else
                switch (input_character) {
                    case 'w':
                        if (selected > 1) {
                            mvwprintw(level_win, 1 + selected, 17, "  ");
                            selected--;
                            mvwprintw(level_win, 1 + selected, 17, "<-");
                        }
                        break;
                    case 's':
                        if (selected < 3) {
                            mvwprintw(level_win, 1 + selected, 17, "  ");
                            selected++;
                            mvwprintw(level_win, 1 + selected, 17, "<-");
                        }
                        break;
                }

            refresh();
        }
    }

    napms(90);
    return selected;
}

void show_levels(WINDOW * level_win) {
    clear();

    refresh();
    box(level_win, 0, 0);
    wrefresh(level_win);

    mvwprintw(level_win, 2, 7, "1- Easy");
    mvwprintw(level_win, 3, 7, "2- Medium");
    mvwprintw(level_win, 4, 7, "3- Hard");
    wrefresh(level_win);
};