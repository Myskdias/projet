#include<stdlib.h>
#include<stdio.h>
#include "board.h"
#include "cell.h"

board_t create_board(int n_line, int n_row, int n_player, int n_hedgehog_player) {
    board_t board;
    board.n_line = n_line;
    board.n_row = n_row;
    board.n_player = n_player;
    board.n_hedgehog_player = n_hedgehog_player;

    printf("Malloc du tableau de cellule\n");
    fflush(stdout);
    //malloc le tableau double entrée
    board.cells = (cell_t**) malloc(n_line * sizeof(void*));

    printf("Malloc de chaque cellule\n");
    fflush(stdout);

    for(int i = 0; i < n_line; i++) {
        board.cells[i] = malloc(n_row * sizeof(cell_t));
    }

    printf("Fin du Malloc\n");
    fflush(stdout);

    return board;
}

void free_board(board_t plateau) {

    printf("Free de chaque cellule\n");
    fflush(stdout);

    for(int i = 0; i < plateau.n_line; i++) {
        free(plateau.cells[i]);
    }

    printf("Free du tableau de cellule\n");
    fflush(stdout);

    free(plateau.cells);
}





