#include "game.h"
#include "board.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include<ctype.h>

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

void do_player_turn(game_t* game, char team) {
    int dice = rand() % 6 + 1; //tire le dé
    printf("Le joueur %c a tiré un %d !\n", team, dice);

    char move;

    ask_yn_question(&move, "Souhaitez-vous bouger verticalement un de vos hérissons ? (y/n)");

    printf("Souhaitez-vous bouger verticalement un de vos hérissons ? (y/n)");

    printf("Etes-vous sûre ? (y/n)");

    printf("Choississez un hérisson à bouger verticalement (donner le numéro de la case ex: b3)");

    printf("Etes-vous sûre ? (y/n)");

    printf("Choississez un hérisson à bouger horizontalement.");

    printf("Etes-vous sûre ? (y/n)");

    printf("Vous ne pouvez pas déplacer de hérisson horizontalement :(");


}

void ask_yn_question(char* c, char* question) {
    do {
        printf("%s", question);
        scanf("%c", c);
    } while (!(tolower(*c) == 'y' || tolower(*c) == 'n'));

}

