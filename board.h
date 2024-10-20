#ifndef BOARD_H
#define BOARD_H

#include"cell.h"

typedef struct board {

    int n_line;
    int n_row;
    cell_t** cells; //faudra le malloc dans le init et le free à la fin du programme
    int n_player;
    int n_hedgehog_player; //nombre de hérisson par joueur

} board_t;

board_t create_board(int n_line, int n_row, int n_player, int n_hedgehog_player);

void free_board(board_t board);

void board_push(board_t* board, int line, int row, char ctn);

void board_pop(board_t* board, int line, int row);

int board_height(board_t* board, int line, int row);

char board_top(board_t* board, int line, int row);

char board_peek(board_t* board, int line, int row, int pos); //pos=0 => top

void cell_print(board_t* board, int line, int row, int slice);

void board_print(board_t* board, int highlighted_line);


#endif//BOARD_H