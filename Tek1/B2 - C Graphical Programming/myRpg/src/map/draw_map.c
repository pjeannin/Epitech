/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_map(game_t *game_struct, window_t *win)
{
    sfRenderWindow_drawSprite(win->window, game_struct->map->map, sfFalse);
}