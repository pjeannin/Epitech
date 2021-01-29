/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_button_end
*/

#include "my_rpg.h"

void check_button_end(window_t *win)
{
    if (win->vec.x >= 725 && win->vec.x <= 1092 &&
        win->vec.y >= 578 && win->vec.y <= 730)
        win->choice = 1;
    else if (win->vec.x >= 725 && win->vec.x <= 1092 &&
        win->vec.y >= 777 && win->vec.y <= 932)
        win->choice = 3;
    else
        win->choice = 0;
}