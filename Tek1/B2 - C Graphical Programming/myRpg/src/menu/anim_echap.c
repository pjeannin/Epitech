/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim_echap
*/

#include "my_rpg.h"

static void anime_echap_end(window_t *win)
{
    if (win->vec.x >= 695 && win->vec.x <= 1176 &&
        win->vec.y >= 651 && win->vec.y <= 834)
        win->choice_echap = 3;
    else
        win->choice_echap = 0;
}

void anime_echap(window_t *win)
{
    if (win->vec.x >= 695 && win->vec.x <= 1176 &&
        win->vec.y >= 176 && win->vec.y <= 361)
        win->choice_echap = 1;
    else if (win->vec.x >= 695 && win->vec.x <= 1176 &&
        win->vec.y >= 413 && win->vec.y <= 598)
        win->choice_echap = 2;
    else
        anime_echap_end(win);
}