/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stat
*/

#include "my_rpg.h"

void init_stats(game_t *game_struct)
{
    game_struct->player_stats.life = 100;
    game_struct->player_stats.level = 1;
    game_struct->player_stats.damage = 10;
    game_struct->player_stats.xp = 10;
}