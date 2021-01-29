/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_guardian(game_t *game_struct, window_t *win)
{
    for (int i = 0; i < 4; ++i)
        if (game_struct->guardian[i].isalave)
            sfRenderWindow_drawSprite(win->window,
            game_struct->guardian[i].sprite, sfFalse);
}