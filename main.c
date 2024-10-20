#include<stdio.h>
#include "board.h"

const int row_number = 3;
const int line_number = 3;


int main(int argc, char** argv) {

    char *line[] = {"a", "b", "c"};



    for (int i = 0; i < 3; i++) {
        printf("Nom %d: %s\n", i + 1, line[i]);
    }
    printf("Nombre de colonne : %d, nombre de ligne : %d\n", row_number, line_number);

    printf("Création du plateau\n");
    fflush(stdout);
    board_t board = create_board(2, 2, 2, 2);

    printf("Test de la fonction #board_push()\n");
    fflush(stdout);
    board_push(&board, 0, 0, 'a');
    printf("Test réussi !\n\n");

    printf("Test de la fonction #board_pop()\n");
    printf("Test numéro 1\n");
    board_pop(&board, 0, 0);
    printf("Test numéro 2\n");
    board_pop(&board, 1, 0);
    printf("Test réussi !\n\n");

    printf("Destruction du plateau\n");
    fflush(stdout);
    free_board(board);

    return 0;
}
