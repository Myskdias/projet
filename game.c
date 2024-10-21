#include "game.h"
#include "board.h"
#include "cell.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

game_t create_game(int n_line, int n_row, int n_player, int n_hedgehog_player) {
    game_t game;

    game.board = create_board(n_line, n_row);
    game.n_hedgehog_player = n_hedgehog_player;
    game.n_player = n_player;
    game.finished = false;

    //init du rand
    srand(time(NULL));

    return game;
}

void do_turn(game_t * game) {
    for(int i = 0; i < game->n_player; i++) {
        do_player_turn(game, 'A' + i);
    }
    //check if someone won
}

//team en maj
void do_player_turn(game_t* game, char team) {
    int dice = rand() % 6 + 1; //tire le dé//TODO adapté le dé
    printf("Le joueur %c a tiré un %d !\n", team, dice);

    char move;
    char yn_answer;

    do {
        ask_yn_question(&move, "Souhaitez-vous bouger verticalement un de vos hérissons ? (y/n)");
        ask_yn_question(&yn_answer, "Etes-vous sûre ? (y/n)");
    } while (yn_answer != 'y');

    if(move == 'y') {
        int line;
        int row;
        do {
            ask_hedgehog(game, team, &line, &row);
            ask_yn_question(&yn_answer, "Etes-vous sûre ? (y/n)");
        } while (yn_answer != 'y');
        
        board_pop(&(game->board), line, row);
        board_push(&(game->board), dice, row, team);
    }

    printf("Choississez un hérisson à bouger horizontalement.");

    printf("Etes-vous sûre ? (y/n)");

    printf("Vous ne pouvez pas déplacer de hérisson horizontalement :(");

}

void ask_yn_question(char* c, char* question) {
    do {
        printf("%s", question);
        scanf("%c", c);
        *c = tolower(*c);
    } while (!(*c == 'y' || *c == 'n'));
}

void ask_hedgehog(game_t* game, char team, int* line, int* row) {
    char* s;
    do {
        printf("Choississez un hérisson à bouger verticalement (donner le numéro de la case ex: b3)");
        scanf("%s", s);
        *line = tolower(s[0]) - 'a';
        *row = (int) s[1] - '0';
    } while (can_be_chosen(game, team, *line, *row));
}  

bool can_be_chosen(game_t* game, char team, int line, int row) {
    if(line < 0 || row < 0 || line >= game->board.n_line || row >= game->board.n_row) {
        printf("Case en dehors du plateau !");
        return false;
    }

    cell_t cell = game->board.cells[line][row];

    if(board_top(&(game->board), line, row) == team) {
        if(cell.trap) {
            if(hedgehog_on_the_left(&(game->board), line, row)) {
                printf("Ce hérisson ne peut pas bouger il y'a des hérissons à sa gauche.");
                return false;
            } else {
               return true; 
            }
        } else {
            return true;
        }
    } else {
        printf("Case invalide : il n'y pas de hérisson vous appartenant sur le dessus de la case.");
        return false;
    }
    return false;
}

bool can_h_move(board_t* board, int line, int row) {
    
}
