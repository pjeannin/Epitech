/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void update_guardian_life(game_t *game_struct)
{
    if (!game_struct->quete[0].done)
        return;
    for (int i = 0; i < 4; ++i)
        if (game_struct->guardian[i].life > 0)
            game_struct->guardian[i].isalave = 1;
        else
            game_struct->guardian[i].isalave = 0;
}