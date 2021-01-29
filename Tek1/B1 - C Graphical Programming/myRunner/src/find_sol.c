/*
** EPITECH PROJECT, 2020
** find_sol.c
** File description:
** runner
*/

#include "my_runner.h"

int find_sol(game_t *game)
{
    game->map = move_beginning(game->map);
    while (game->map->next) {
        if ((game->mario->pos.x + 130 > (game->map->element)->pos.x
        && game->mario->pos.x < ((game->map->element)->pos.x + 120))
        && game->map->element->pos.y > game->mario->pos.y + 120)
            return (game->map->element->pos.y);
        game->map = game->map->next;
    }
    return (960);
}