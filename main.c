#define SIZE 4
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------------------------------BOOL FUNCTIONS--------------------------------------

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

//Return true if a tile equal 0
bool has_empty_tile(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (a_board[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

//--------------------------------------END BOOL FUNCTIONS--------------------------------------


//--------------------------------------VOID FUNCTIONS--------------------------------------

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
    if (has_empty_tile(a_board)) {
        int row_rand = rand() % SIZE;
        int col_rand = rand() % SIZE;

        while (a_board[row_rand][col_rand] != 0) {
            row_rand = rand() % SIZE;
            col_rand = rand() % SIZE;
        }
        a_board[row_rand][col_rand] = 2;
    }

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

//--------------------------------------END VOID FUNCTIONS--------------------------------------

//--------------------------------------RIGHT FUNCTIONS--------------------------------------

//Move every element to the right
void move_right(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int target_col = 3;

        for (int j = SIZE - 1; j > - 1; j--) {
            if (a_board[i][j] != 0) {
                a_board[i][target_col] = a_board[i][j];

                if (target_col != j) {
                    a_board[i][j] = 0;
                }
                target_col--;
            }
        }
    }
}

//Merge elements to the tight together only if they have the same value and different from 0
void merge_right(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (a_board[i][j] == a_board[i][j-1] && a_board[i][j] != 0) {
                a_board[i][j] += a_board[i][j-1];
                a_board[i][j-1] = 0;
            }
        }
    }
}

//Groups "right" functions
bool play_right(int a_board[SIZE][SIZE]) {
    int temp_board[SIZE][SIZE];

    //Copy board passed as parameter to a temporary board, to compare it after
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = a_board[i][j];
        }
    }
    move_right(a_board);
    merge_right(a_board);
    move_right(a_board);

    //Verify is the board as changed
    if (boards_are_equal(temp_board,a_board) == false) {
        return true;
    }else {
        return false;
    }
}
//--------------------------------------END RIGHT FUNCTIONS--------------------------------------

//--------------------------------------LEFT FUNCTIONS--------------------------------------

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

//Merge elements to the left together only if they have the same value and different from 0
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

    //Copy board passed as parameter to a temporary board, to compare it after
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = a_board[i][j];
        }
    }
    move_left(a_board);
    merge_left(a_board);
    move_left(a_board);

    //Verify is the board as changed
    if (boards_are_equal(temp_board,a_board) == false) {
        return true;
    }else {
        return false;
    }
}

//--------------------------------------END LEFT FUNCTIONS--------------------------------------


//--------------------------------------UP FUNCTIONS--------------------------------------

// move every element to the up
void move_up(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int target_row = 0;

        for (int j = 0; j < SIZE; j++) {
            if (a_board[j][i] != 0) {
                a_board[target_row][i] = a_board[j][i];

                if (target_row != j) {
                    a_board[j][i] = 0;
                }

                target_row++;
            }
        }
    }
}

//Merge elements to the up together only if they have the same value and different from 0
void merge_up(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (a_board[j][i] == a_board[j+1][i] && a_board[j][i] != 0) {
                a_board[j][i] += a_board[j+1][i];
                a_board[j+1][i] = 0;
            }
        }
    }
}

//Groups "up" functions
bool play_up(int a_board[SIZE][SIZE]) {
    int temp_board[SIZE][SIZE];

    //Copy board passed as parameter to a temporary board, to compare it after
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = a_board[i][j];
        }
    }
    move_up(a_board);
    merge_up(a_board);
    move_up(a_board);

    //Verify is the board as changed
    if (boards_are_equal(temp_board,a_board) == false) {
        return true;
    }else {
        return false;
    }
}

//--------------------------------------END UP FUNCTIONS--------------------------------------


//--------------------------------------DOWN FUNCTIONS--------------------------------------

// move every element to the down
void move_down(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int target_row = SIZE - 1;

        for (int j = SIZE - 1; j > - 1; j--) {
            if (a_board[j][i] != 0) {
                a_board[target_row][i] = a_board[j][i];

                if (target_row != j) {
                    a_board[j][i] = 0;
                }

                target_row--;
            }
        }
    }
}

//Merge elements to the down together only if they have the same value and different from 0
void merge_down(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (a_board[j][i] == a_board[j-1][i] && a_board[j][i] != 0) {
                a_board[j][i] += a_board[j-1][i];
                a_board[j-1][i] = 0;
            }
        }
    }
}

//Groups "down" functions
bool play_down(int a_board[SIZE][SIZE]) {
    int temp_board[SIZE][SIZE];

    //Copy board passed as parameter to a temporary board, to compare it after
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = a_board[i][j];
        }
    }
    move_down(a_board);
    merge_down(a_board);
    move_down(a_board);

    //Verify is the board as changed
    if (boards_are_equal(temp_board,a_board) == false) {
        return true;
    }else {
        return false;
    }
}

//--------------------------------------END DOWN FUNCTIONS--------------------------------------

int main() {
    srand(time(NULL));
    int board_left[SIZE][SIZE] = {
        {0, 2, 2, 2}, // Attendu 4, 2, 0, 0
        {2, 0, 0, 2}, // Attendu 4, 0, 0, 0
        {2, 2, 2, 2}, // Attendu 4, 4, 0, 0
        {4, 4, 8, 8}  // Attendu 8, 16, 0, 0
    };

    int board_right[SIZE][SIZE] = {
        {0, 2, 2, 2},   // attendu après droite : 0, 0, 2, 4
        {2, 0, 0, 2},   // attendu : 0, 0, 0, 4
        {2, 2, 2, 2},   // attendu : 0, 0, 4, 4
        {4, 4, 8, 8}    // attendu : 0, 0, 8, 16
    };


    int board_full[SIZE][SIZE] = {
        {2, 4, 8, 16},
        {4, 8, 16, 32},
        {8, 16, 32, 64},
        {16, 32, 64, 128}
    };

    int board_up[SIZE][SIZE] = {
        {2, 8, 0, 0},
        {2, 8, 4, 2},
        {4, 0, 4, 0},
        {4, 0, 8, 2}
    };

    int board_down[SIZE][SIZE] = {
        {2, 8, 0, 0}, // 0, 0, 0, 0
        {2, 8, 4, 2}, // 0, 0, 0, 0
        {4, 0, 4, 0}, // 4, 0, 8, 0
        {4, 0, 8, 2}  // 8, 16, 8, 4
    };

    printf("----board_full----\n");
    printf("Premier affichage\n");
    print_board(board_full);
    printf("Deuxieme affichage\n");
    if (play_down(board_full)) {
        spawn_tile(board_full);
        print_board(board_full);
    }else {
        printf("Aucun mouvement vers le haut\n");
    }

    printf("----board_down----\n");
    printf("Premier affichage\n");
    print_board(board_down);
    printf("Deuxieme affichage\n");
    if (play_down(board_down)) {
        spawn_tile(board_down);
        print_board(board_down);
    }else {
        printf("Aucun mouvement vers le haut\n");
    }

    //init_board(board);
    //spawn_tile(board);
    //spawn_tile(board);

    return 0;
}