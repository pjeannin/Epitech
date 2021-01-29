/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static void turn_gardian(game_t *game_struct, int i)
{
    if (game_struct->guardian[i].pos.x > MAP_RIGHT - 150 ||
        game_struct->guardian[i].pos.x < MAP_LEFT + 150) {
            game_struct->guardian[i].move_side *= -1;
            game_struct->guardian[i].pos.x += game_struct->guardian[i].speed *
            game_struct->guardian[i].move_side;
            game_struct->guardian[i].rect.top =
            game_struct->guardian[i].rect.top == 0 ? 160 : 0;
            }
}

void move_guardian(game_t *game_struct)
{
    static int call = 0;

    if (call++ % 4)
            return;
    for (int i = 0; i < 4; ++i) {
        game_struct->guardian[i].rect.left +=
        (game_struct->guardian[i].rect.left == 800 ? -800 : 160);
        sfSprite_setTextureRect(game_struct->guardian[i].sprite,
        game_struct->guardian[i].rect);
        game_struct->guardian[i].pos.x += game_struct->guardian[i].speed *
        game_struct->guardian[i].move_side;
        turn_gardian(game_struct, i);
        sfSprite_setPosition(game_struct->guardian[i].sprite,
        game_struct->guardian[i].pos);
    }
}