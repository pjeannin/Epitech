/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void end_menu(game_t *game_struct, window_t *win)
{
    draw_map(game_struct, win);
    sfRenderWindow_drawSprite(win->window, game_struct->win_menu, sfFalse);
}