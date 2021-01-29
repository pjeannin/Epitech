/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_objects(game_t *game_struct, window_t *win, charact_t *charact)
{
    for (int i = 0; i < 4; ++i)
        if (charact->charact_pos.x > game_struct->object_list[i].pos.x - 200
        && charact->charact_pos.x < game_struct->object_list[i].pos.x + 200
        && charact->charact_pos.y > game_struct->object_list[i].pos.y - 200
        && charact->charact_pos.y < game_struct->object_list[i].pos.y + 200
        && !game_struct->object_list[i].istake)
            sfRenderWindow_drawSprite(win->window,
            game_struct->object_list[i].sprite, sfFalse);
}