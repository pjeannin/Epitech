/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static void boss_life(game_t *game_struct)
{
    if (game_struct->quete[1].done)
        game_struct->boss.isalave = 1;
    if (game_struct->boss.life <= 0)
        game_struct->boss.isalave = 0;
}

void boss_damage(game_t *game_struct, charact_t *charact)
{
    boss_life(game_struct);
    if (game_struct->boss.isalave && !game_struct->boss.has_shoot
    && charact->charact_pos.x > game_struct->boss.pos.x - 60
    && charact->charact_pos.x < game_struct->boss.pos.x + 430
    && charact->charact_pos.y > game_struct->boss.pos.y - 60
    && charact->charact_pos.y < game_struct->boss.pos.y + 430) {
        game_struct->player_stats.life -= game_struct->boss.damage;
        game_struct->boss.has_shoot = 40;
    } else if (game_struct->boss.has_shoot)
        --game_struct->boss.has_shoot;
}