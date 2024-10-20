#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
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
        printf("Be careful, you are trying to remove a hedgehog from a cell which doesn't have any.\n");
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

//Dessine une line de la cellule, slice désigne quelle ligne on dessine : 0 pour celle du haut
void cell_print(board_t* board, int line, int row, int slice) {
    cell_t cell = (*board).cells[line][row];
    switch (slice) {
        case 0:
            if(cell.trap) {
                printf(" vvv ");
            } else {
                printf(" --- ");
            }
            break;
        case 1:
            print_left(cell);

            if(board_height(board, line, row) > 0) {
                print_team(board, line, row);
            } else {
                printf("   ");
            }

            print_right(cell);
            break;
        case 2:
            print_left(cell);

            switch (board_height(board, line, row)) {
                case 0:
                    printf("   ");
                    break;
                case 1:
                    print_team(board, line, row);
                    break;
                case 2:
                    char t1 = tolower(board_peek(board, line, row, 1));
                    printf("%c%c%c", t1, t1, t1);
                    break;
                case 3:
                    char t2 = tolower(board_peek(board, line, row, 1));
                    char t3 = tolower(board_peek(board, line, row, 2));
                    printf("%c %c", t2, t3);
                    break;
                default:
                    char t4 = tolower(board_peek(board, line, row, 1));
                    char t5 = tolower(board_peek(board, line, row, 2));
                    char t6 = tolower(board_peek(board, line, row, 3));
                    printf("%c%c%c", t4, t5, t6);
                    break;
            }

            print_right(cell);
            break;
        case 3:
            printf(" ");
            print_bottom_char(cell);

            int height = board_height(board, line, row);
            if(height > 1) {
                printf("%d", height);
            } else {
                print_bottom_char(cell);
            }

            print_bottom_char(cell);
            printf(" ");
            break;
        default:
            printf("This shouldn't happen !");
            break;
    }
}

void print_bottom_char(cell_t cell) {
    if(cell.trap) {
        printf("^");
    } else {
        printf("-");
    }
}

void print_left(cell_t cell) {
    if(cell.trap) {
        printf(">");
    } else {
        printf("|"); 
    }
}

void print_right(cell_t cell) {
    if(cell.trap) {
        printf("<");
    } else {
        printf("|"); 
    }
}

void print_team(board_t* board, int line, int row) {
    char team = toupper(board_top(board, line, row));
    printf("%c%c%c", team, team, team);
}


