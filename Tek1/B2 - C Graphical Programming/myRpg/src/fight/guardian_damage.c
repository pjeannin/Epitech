/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void guardian_damage(game_t *game_struct, charact_t *charact)
{
    for (int i = 0; i < 4; ++i)
        if (game_struct->guardian[i].isalave
        && !game_struct->guardian[i].has_shoot
        && charact->charact_pos.x > game_struct->guardian[i].pos.x - 20
        && charact->charact_pos.x < game_struct->guardian[i].pos.x + 180
        && charact->charact_pos.y > game_struct->guardian[i].pos.y - 20
        && charact->charact_pos.y < game_struct->guardian[i].pos.y + 180) {
            game_struct->player_stats.life -= 20;
            game_struct->guardian[i].has_shoot = 90;
        } else if (game_struct->guardian[i].has_shoot > 0)
            --game_struct->guardian[i].has_shoot;
}