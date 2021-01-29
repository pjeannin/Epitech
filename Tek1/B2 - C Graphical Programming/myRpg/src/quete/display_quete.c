/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "my_rpg.h"

void display_quete(game_t *game_struct, window_t *win)
{
    static int call = 0;

    if (game_struct->need_to_display_quete) {
        call = 0;
        game_struct->need_to_display_quete = 0;
    }
    if (call++ < 2000)
        sfRenderWindow_drawSprite(win->window,
        game_struct->quete[game_struct->cur_quete].sprite, sfFalse);
}