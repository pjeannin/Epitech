/*
** EPITECH PROJECT, 2020
** jump.c
** File description:
** runner
*/

#include "my_runner.h"

void jump(game_t *game)
{
    static int call = 0;

    if (game->up != 0) {
        ++call;
        game->mario->pos.y -= game->up;
        if (call % 5 == 0)
            game->up -= 5;
    } else if (game->mario->pos.y + 229 < game->sol)
        game->mario->pos.y += 15;
}