cmake_minimum_required(VERSION 4.2)
project(2048 C)

set(CMAKE_C_STANDARD 11)

add_executable(2048
        main.c
        game.c
        game.h)
add_executable(game game.c)
