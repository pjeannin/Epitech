/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static void update_xp(game_t *game_struct)
{
    int xp = 10;

    for (int i = 0; i < 4; ++i)
        if (game_struct->quete[0].done && !game_struct->guardian[i].isalave)
            xp += 5;
    game_struct->player_stats.xp = xp;
}

void update_level(game_t *game_struct)
{
    update_xp(game_struct);
    game_struct->player_stats.level = game_struct->player_stats.xp / 10;
}