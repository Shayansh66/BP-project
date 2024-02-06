cmake_minimum_required(VERSION 3.27)
project(my_project C)

set(CMAKE_C_STANDARD 17)

add_executable(my_project main.c
        components.h
        menu.c
        start_up.c
        level.c
        random_make.c
        create_items.c
        key_detector.c
        gameplay.c
        add_remove_item.h
        movements.c
        spawn_enemy.c)
