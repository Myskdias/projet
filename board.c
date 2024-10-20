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

//Rajoute un hérisson sur le haut de la pile d'une case
void board_push(board_t* board, int line, int row, char ctn) {
    cell_t *cell = &(*board).cells[line][row];
    (*cell).hedgehogs[(*cell).n_hedgehog] = ctn;
    (*cell).n_hedgehog++;
}

//Enlève le hérisson qui était sur le haut de la pile de la case
void board_pop(board_t* board, int line, int row) {
    cell_t *cell = &(*board).cells[line][row];
    printf("Il y %d hérisson(s)\n",(*cell).n_hedgehog);
    if((*cell).n_hedgehog > 0) {
        (*cell).n_hedgehog--;
    } else {
        printf("Be careful, you are trying to remove a hedgehog from a cell who doesn't have any.\n");
    }
}

//Donne le nombre de hérisson sur la pile
int board_height(board_t* board, int line, int row) {
    return (*board).cells[line][row].n_hedgehog;
}

//Donne le nom de l'équipe du hérisson sur le dessus de la pile
char board_top(board_t* board, int line, int row) {
    return board_peek(board, line, row, 0);
}

//Donne le nom de l'équipe du hérisson à la position pos //pos=0 => top
char board_peek(board_t* board, int line, int row, int pos) {
    cell_t cell = (*board).cells[line][row];
    return cell.hedgehogs[cell.n_hedgehog - 1 - pos];
} 

