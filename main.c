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

//return "true" if boards are equal
bool boards_are_equal(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}


//LEFT FUNCTIONS

//Move every element to the left
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

//Merge elements together only if they have the same value and different from 0
void merge_left(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (a_board[i][j] == a_board[i][j+1] && a_board[i][j] != 0) {
                a_board[i][j] += a_board[i][j+1];
                a_board[i][j+1] = 0;
            }
        }
    }
}

//Groups "left" functions
bool play_left(int a_board[SIZE][SIZE]) {
    int temp_board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = a_board[i][j];
        }
    }
    move_left(a_board);
    merge_left(a_board);
    move_left(a_board);
    if (boards_are_equal(temp_board,a_board) == false) {
        return true;
    }else {
        return false;
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

    //init_board(board);
    //spawn_tile(board);
    //spawn_tile(board);

    printf("Premier affichage\n");
    print_board(board);
    printf("Deuxieme affichage\n");
    if (play_left(board)) {
        spawn_tile(board);
        print_board(board);
    }
    return 0;
}