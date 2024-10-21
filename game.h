#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <stdbool.h>

typedef struct game {

    board_t board;
    int n_player;
    int n_hedgehog_player; //nombre de hérisson par joueur
    bool finished;

} game_t;

game_t create_game(int n_line, int n_row, int n_player, int n_hedgehog_player);

void do_turn(game_t* game);

void do_player_turn(game_t* game, char team);

void ask_yn_question(char* c, char* question);

void ask_hedgehog(game_t* game, char team, int* line, int* row);

bool can_be_chosen(game_t* game, char team, int line, int row);

#endif//GAME_H