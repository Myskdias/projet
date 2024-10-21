#include <stdbool.h>
#include<stdio.h>
#include "board.h"

const int n_row = 3;
const int n_line = 3;


int main(int argc, char** argv) {

    char *line[] = {"a", "b", "c"};



    for (int i = 0; i < 3; i++) {
        printf("Nom %d: %s\n", i + 1, line[i]);
    }
    printf("Nombre de colonne : %d, nombre de ligne : %d\n", n_row, n_line);

    printf("Création du plateau\n");
    fflush(stdout);
    board_t board = create_board(n_line, n_row);

    printf("Test de la fonction #board_push()\n");
    fflush(stdout);
    board_push(&board, 0, 0, 'a');
    board_push(&board, 0, 0, 'b');
    board_push(&board, 0, 0, 'c');
    printf("Test réussi !\n\n");

    printf("Test de la fonction #board_height()\n");
    int i = board_height(&board, 0, 0);
    printf("Il y %d hérisson(s) sur la pile\n", i);
    printf("Test réussi !\n\n");

    printf("Test de la fonction #board_top()\n");
    char c = board_top(&board, 0, 0);
    printf("Le hérisson %c est sur le dessus de la pile\n", c);
    printf("Test réussi !\n\n");


    board.cells[0][0].trap = true;
    printf("Test de la fonction #cell_print()\n");
    for(int j = 0; j < 4; j++) {
        cell_print(&board, 0, 0, j);
        printf("\n");
    }
    printf("Test réussi !\n\n");

    printf("Test de la fonction #board_print()\n");
    board_print(&board, -1);
    printf("Test réussi !\n\n");

    printf("Test de la fonction #board_print()\n");
    board_print(&board, 0);
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
