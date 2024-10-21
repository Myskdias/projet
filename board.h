#ifndef BOARD_H
#define BOARD_H

#include"cell.h"

typedef struct board {

    int n_line;
    int n_row;
    cell_t** cells; //faudra le malloc dans le init et le free à la fin du programme

} board_t;

board_t create_board(int n_line, int n_row);

void free_board(board_t board);

//Rajoute un hérisson sur le haut de la pile d'une case
void board_push(board_t* board, int line, int row, char ctn);

//Enlève le hérisson qui était sur le haut de la pile de la case
void board_pop(board_t* board, int line, int row);

//Donne le nombre de hérisson sur la pile
int board_height(board_t* board, int line, int row);

//Donne le nom de l'équipe du hérisson sur le dessus de la pile
char board_top(board_t* board, int line, int row);

//Donne le nom de l'équipe du hérisson à la position pos
char board_peek(board_t* board, int line, int row, int pos); //pos=0 => top

//Dessine une ligne de la cellule, slice désigne quelle ligne on dessine : 0 pour celle du haut
void cell_print(board_t* board, int line, int row, int slice);

//Dessine le plateau
void board_print(board_t* board, int highlighted_line);

void print_first_line(board_t* board);

void print_raws_name(board_t* board);

void print_line(board_t* board, int line, int highlighted_line);

void print_line_slice(board_t* board, int line, int highlighted_line, int slice);

void print_line_beginning(int line, int highlighted_line);

void print_bottom_char(cell_t cell);

void print_left(cell_t cell);

void print_right(cell_t cell);

void print_team(board_t* board, int line, int row);

#endif//BOARD_H