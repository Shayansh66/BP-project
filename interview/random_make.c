#include "components.h"


int generate_main_seed() {
    long long int the_time = Time, main_seed, temp_1, temp_2;

    temp_1 = the_time % 1000;
    temp_2 = temp_1 % 100;
    temp_1 /= 100;
    temp_2 += (temp_1 % 2 + 1) * 100;

    main_seed = temp_2 * temp_2;

    temp_1 = main_seed / 10000;
    temp_2 = main_seed % 100;

    temp_1 = temp_1 * 111 + temp_2;

    main_seed = temp_1 * temp_1 * temp_1;
    return (int) main_seed;
}

int number_maker(int number, int nth) {
    bool is_odd = nth % 2;
    number %= 1000;
    number += nth;
    number *= 13;
    number += 101;
    int temp_1, temp_2, temp_3, number_2;
    double remaining = number / 7.0;

    temp_1 = (int) remaining % 10;

    number_2 = remaining * 10000;

    temp_3 = number_2 % 10;

    if (is_odd)
        number_2 /= 100;
    else
        number_2 /= 10;
    temp_2 = number_2 % 10;

    return temp_1 * 100 + temp_2 * 10 + temp_3;
}