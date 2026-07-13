#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"

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
                bool moved = false;
                switch (direction) {
                    case 'z':
                        moved = play_up(board);
                        break;
                    case 'q':
                        moved = play_left(board);
                        break;
                    case 's':
                        moved = play_down(board);
                        break;
                    case 'd':
                        moved = play_right(board);
                        break;
                }

                if (moved) {
                    spawn_tile(board);
                    print_board(board);
                }else {
                    printf("No movement possible into this direction !\n");
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
