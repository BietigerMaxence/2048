#ifndef INC_2048_GAME_H
#define INC_2048_GAME_H

#define SIZE 4
#include <stdbool.h>

bool can_move(int a_board[SIZE][SIZE]);
bool boards_are_equal(int a[SIZE][SIZE], int b[SIZE][SIZE]);
bool has_empty_tile(int a_board[SIZE][SIZE]);

void init_board(int a_board[SIZE][SIZE]);
void spawn_tile(int a_board[SIZE][SIZE]);
void print_board(int a_board[SIZE][SIZE]);
void copy_board(int source[SIZE][SIZE], int destination[SIZE][SIZE]);

void move_right(int a_board[SIZE][SIZE]);
void merge_right(int a_board[SIZE][SIZE]);
bool play_right(int a_board[SIZE][SIZE]);

void move_left(int a_board[SIZE][SIZE]);
void merge_left(int a_board[SIZE][SIZE]);
bool play_left(int a_board[SIZE][SIZE]);

void move_up(int a_board[SIZE][SIZE]);
void merge_up(int a_board[SIZE][SIZE]);
bool play_up(int a_board[SIZE][SIZE]);

void move_down(int a_board[SIZE][SIZE]);
void merge_down(int a_board[SIZE][SIZE]);
bool play_down(int a_board[SIZE][SIZE]);

#endif //INC_2048_GAME_H