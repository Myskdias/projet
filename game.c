#include "game.h"
#include "board.h"
#include <stdbool.h>

game_t create_game(int n_line, int n_row, int n_player, int n_hedgehog_player) {
    game_t game;

    game.board = create_board(n_line, n_row);
    game.n_hedgehog_player = n_hedgehog_player;
    game.n_player = n_player;
    game.finished = false;

    return game;
}

