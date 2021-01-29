/*
** EPITECH PROJECT, 2020
** chech_end.c
** File description:
** runner
*/

#include "my_runner.h"

int check_end(game_t *game, int *screen)
{
    while (game->map->next)
        game->map = game->map->next;
    if (game->mario->pos.x - 200 > game->end)
        *screen = 5;
}