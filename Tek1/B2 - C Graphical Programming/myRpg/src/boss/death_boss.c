/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void death_boss(game_t *game_struct)
{
    static int call = 0;

    if (call++ % 2 && game_struct->boss.rect.left < 1600) {
        game_struct->boss.rect.left += game_struct->boss.rect.width;
        sfSprite_setTextureRect(game_struct->boss.sprite,
        game_struct->boss.rect);
    }
}