/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_echap
*/

#include "my_rpg.h"

static void draw_echap_end(window_t *win)
{
    if (win->choice_echap == 2)
        sfRenderWindow_drawSprite(win->window, tabgame[1].S_menugame, NULL);
    if (win->choice_echap == 3)
        sfRenderWindow_drawSprite(win->window, tabgame[2].S_menugame, NULL);
}

int draw_echap(window_t *win)
{
    if (win->echap_switch == 1) {
        sfRenderWindow_drawSprite(win->window, tabgame[3].S_menugame, NULL);
        if (win->choice_echap == 1)
            sfRenderWindow_drawSprite(win->window, tabgame[0].S_menugame, NULL);
        draw_echap_end(win);
    }
    return (0);
}