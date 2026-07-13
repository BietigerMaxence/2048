#define SIZE 4
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------------------------------BOOL FUNCTIONS--------------------------------------

//return true if the board can move
bool can_move(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            //return true if if the tile equal 0
            if (a_board[i][j] == 0) {
                return true;
            }

            if (j < SIZE - 1) {
                //return true if a tile at it's right are equal
                if (a_board[i][j] == a_board[i][j+1]) {
                    return true;
                }
            }

            if (i < SIZE - 1) {
                //return true if a tile and it below one are equal
                if (a_board[i][j] == a_board[i+1][j]) {
                    return true;
                }
            }
        }
    }
    //return false if no more move is possible
    return false;
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
            if (j == SIZE - 1) {
                continue;
            }
            printf(" | ");
        }
        printf("\n---+---+---+---\n");
    }
}

void copy_board(int source[SIZE][SIZE], int destination[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

//--------------------------------------END VOID FUNCTIONS--------------------------------------

//--------------------------------------RIGHT FUNCTIONS--------------------------------------

//Move every element to the right
void move_right(int a_board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int target_col = SIZE - 1;

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
    copy_board(a_board, temp_board);

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
    copy_board(a_board, temp_board);

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
    copy_board(a_board, temp_board);

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
    copy_board(a_board, temp_board);

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

    int board[SIZE][SIZE];
    /*
    int board_test[SIZE][SIZE]={
        {2, 4, 8, 16},
        {4, 8, 16, 32},
        {8, 16, 32, 64},
        {16, 32, 64, 128}
    };
    */

    char direction;


    init_board(board);
    spawn_tile(board);
    spawn_tile(board);

    print_board(board);

    while (can_move(board)) {
        if (scanf(" %c", &direction) == 1) {// NOLINT(cert-err34-c)
            direction = tolower(direction);
            if (direction == 'z' || direction == 'q' || direction == 's' || direction == 'd') {
                switch (direction) {
                    case 'z':
                        if (play_up(board)) {
                            spawn_tile(board);
                            print_board(board);
                            break;
                        }else {
                            printf("No movement to the top\n");
                            break;
                        }
                    case 'q':
                        if (play_left(board)) {
                            spawn_tile(board);
                            print_board(board);
                            break;
                        }else {
                            printf("No movement to the left\n");
                            break;
                        }
                    case 's':
                        if (play_down(board)) {
                            spawn_tile(board);
                            print_board(board);
                            break;
                        }else {
                            printf("No movement to the bottom\n");
                            break;
                        }
                    case 'd':
                        if (play_right(board)) {
                            spawn_tile(board);
                            print_board(board);
                            continue;
                        }else {
                            printf("No movement to the right\n");
                            continue;
                        }
                }
            }else {
                printf("Invalid direction, please choose another one:\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
                continue;
            }
        }else {
            printf("Invalid character, please choose another one:\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }
    }
    printf("Game Over!\n");
    return 0;
}