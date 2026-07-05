#define SIZE 4
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
        for (int j = 0; j < SIZE; j++) {
            if (a_board[i][j] == 1) {
                int target_col = i;
                int target_row = j;
            }
        }
    }

}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE];


    init_board(board);
    spawn_tile(board);
    spawn_tile(board);
    print_board(board);
}
