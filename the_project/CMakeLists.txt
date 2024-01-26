cmake_minimum_required(VERSION 3.26)
project(the_project C)

set(CMAKE_C_STANDARD 17)

add_executable(the_project main.c
        menu.c
        gameplay.c
        components.h)
