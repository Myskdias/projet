#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include "board.h"
#include "cell.h"

board_t create_board(int n_line, int n_row) {
    board_t board;
    board.n_line = n_line;
    board.n_row = n_row;

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

//Dessine le plateau
void board_print(board_t* board, int highlighted_line) {
    print_first_line(board);
    printf("\n");
    print_raws_name(board);

    for(int i = 0; i < (*board).n_line; i++) {
        print_line(board, i, highlighted_line);
    }
    print_raws_name(board);
}

void print_first_line(board_t* board) {
    printf("     START");
    for(int i = 0; i < (*board).n_row - 2; i++) {
        printf("     ");
    }
    printf("FINISH\n");
}

void print_raws_name(board_t* board) {
    printf("     ");//5 blank spaces
    for(int i = 0; i < (*board).n_row; i++) {
        printf("  row ");
    }
    printf("\n");

    //second line with the names
    printf("     ");//5 blank spaces
    for(int i = 0; i < (*board).n_row; i++) {
        printf("   %c  ", 'a' + i);
    }
    printf("\n");
}

void print_line(board_t* board, int line, int highlighted_line) {
    //represent 5 lines on the terminal

    //line 0
    printf("    ");//4 white spaces
    print_line_slice(board, line, highlighted_line, 0);

    //line 1
    printf("line");
    print_line_slice(board, line, highlighted_line, 1);

    //line 2
    printf("  %d ", line + 1);
    print_line_slice(board, line, highlighted_line, 2);

    //line 3
    printf("    ");//4 blank spaces
    print_line_slice(board, line, highlighted_line, 3);

    //line 4 : blank line
    printf("\n");
}

void print_line_slice(board_t* board, int line, int highlighted_line, int slice) {
    print_line_beginning(line, highlighted_line);
    for(int j = 0; j < (*board).n_row; j++) {
        printf(" ");
        cell_print(board, line,j, slice);
    }
    printf("\n");
}

void print_line_beginning(int line, int highlighted_line) {
    if(line == highlighted_line) {
        printf(">");
    } else {
        printf(" ");
    }
}

//teste si il y a au moins un hérisson à gauche de notre case
bool hedgehog_on_the_left(board_t* board, int line, int row) {
    for(int j = 0; j < row; j++) {
        if(board_height(board, line, j) > 0) {
            return true;
        }
    }
    return false;
}
