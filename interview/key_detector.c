#include "components.h"


int detect_entered_key(int input_key) {
    if (input_key == KEY_UP || input_key == 'W' || input_key == 'w')
        return (int) 'w';
    else if (input_key == KEY_DOWN || input_key == 'S' || input_key == 's')
        return (int) 's';
    else if (input_key == KEY_RIGHT || input_key == 'D' || input_key == 'd')
        return (int) 'd';
    else if (input_key == KEY_LEFT || input_key == 'A' || input_key == 'a')
        return (int) 'a';
    else if (input_key == '\n' || input_key == ' ' || input_key == 27)
        return input_key;
    else if (input_key == '1' || input_key == '2' || input_key == '3' || input_key == '4')
        return input_key;
    else {
        return 0;
    }
}

int take_input_key() {
    int input_char;
    flushinp();
    input_char = getch();
    if (input_char == ERR) {
        return 0;
    }
    else
        return detect_entered_key(input_char);

}