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

        for (int j = SIZE - 1; j > 0; j--) {
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

    //init_board(board);
    //spawn_tile(board);
    //spawn_tile(board);


    printf("Premier affichage\n");
    print_board(board_right);
    printf("Deuxieme affichage\n");
    if (play_right(board_right)) {
        //spawn_tile(board_right);
        print_board(board_right);
    }else {
        printf("Aucun mouvement vers la gauche\n");
    }

    /*
    bool empty = has_empty_tile(board_full);
    printf("%d ", empty);
    */
    return 0;
}