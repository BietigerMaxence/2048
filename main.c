#define SIZE 4
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fill the board with 0
void init_board(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a_board[i][j] = 0;
        }
    }
}

//Choose a random tile and place it a 2
void spawn_tile(int a_board[SIZE][SIZE]) {
    int row_rand = rand() % SIZE;
    int col_rand = rand() % SIZE;

    while (a_board[row_rand][col_rand] != 0) {
        row_rand = rand() % SIZE;
        col_rand = rand() % SIZE;
    }
    a_board[row_rand][col_rand] = 2;
}

//Print the board
void print_board(int a_board[SIZE][SIZE]) {
    printf("---+---+---+---\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        for (int j = 0; j < SIZE; j++) {
            printf("%d", a_board[i][j]);
            if (j == 3) {
                continue;
            }
            printf(" | ");
        }
        printf("\n---+---+---+---\n");
    }
}

//Fonction pas terminé
void move_left(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int target_col = 0;

        for (int j = 0; j < SIZE; j++) {
            if (a_board[i][j] != 0) {
                a_board[i][target_col] = a_board[i][j];

                if (target_col != j) {
                    a_board[i][j] = 0;
                }

                target_col++;
            }
        }
    }
}

void merge_left(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 2; j++) {
            if (a_board[i][j] == a_board[i][j+1] && a_board[i][j] != 0) {
                a_board[i][j] += a_board[i][j+1];
                a_board[i][j+1] = 0;

            }
        }
    }
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE] = {
        {0, 2, 2, 2}, // Attendu 4, 2, 0, 0
        {2, 0, 0, 2}, // Attendu 4, 0, 0, 0
        {2, 2, 2, 2}, // Attendu 4, 4, 0, 0
        {4, 4, 8, 8}  // Attendu 8, 16, 0, 0
    };

    int board1[SIZE][SIZE] = {
        {2, 2, 4, 0}, // Attendu 4, 4, 0, 0
        {4, 4, 4, 0}, // Attendu 8, 4, 0, 0
        {2, 4, 4, 4}, // Attendu 2, 8, 4, 0
        {0, 0, 0, 0}  // Attendu 0, 0 0, 0
    };

    //init_board(board);
    //spawn_tile(board);
    //spawn_tile(board);

    printf("board\n");
    print_board(board);
    move_left(board);
    merge_left(board);
    move_left(board);
    print_board(board);

    printf("board1\n");
    print_board(board1);
    move_left(board1);
    merge_left(board1);
    move_left(board1);
    print_board(board1);
}