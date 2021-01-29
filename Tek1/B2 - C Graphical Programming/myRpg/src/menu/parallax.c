/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

int set_pos_par(void)
{
    tabpar[0].par_pos.x += 0.1;
    tabpar[1].par_pos.x += 0.1;
    tabpar[2].par_pos.x += 0.4;
    tabpar[3].par_pos.x += 0.4;
    tabpar[4].par_pos.x += 0.6;
    tabpar[5].par_pos.x += 0.6;
    tabpar[6].par_pos.x += 0.8;
    tabpar[7].par_pos.x += 0.8;
    tabpar[8].par_pos.x += 1;
    tabpar[9].par_pos.x += 1;
    tabpar[10].par_pos.x += 1.2;
    tabpar[11].par_pos.x += 1.2;
    tabpar[12].par_pos.x += 1.4;
    tabpar[13].par_pos.x += 1.4;
    tabpar[14].par_pos.x += 1.6;
    tabpar[15].par_pos.x += 1.6;
    return (0);
}

int check_key_echap(window_t *win)
{
    if (win->echap_switch == 1) {
        if (win->event.key.code == sfKeyEscape && win->event.key.type ==
        sfEvtKeyPressed)
            win->echap_switch = 0;
    }
    else if (win->event.key.code == sfKeyEscape && win->event.key.type ==
    sfEvtKeyPressed)
        win->echap_switch = 1;
    if (win->echap_switch == 1)
        press_echap(win);
    return (0);
}

int base_pos_echap(void)
{
    tabgame[0].menugame_pos.x = 695;
    tabgame[0].menugame_pos.y = 175;
    tabgame[1].menugame_pos.x = 695;
    tabgame[1].menugame_pos.y = 412;
    tabgame[2].menugame_pos.x = 695;
    tabgame[2].menugame_pos.y = 650;
    tabgame[3].menugame_pos.x = 624;
    tabgame[3].menugame_pos.y = 100;
    return (0);
}

int parallax(void)
{
    set_pos_par();
    for (int i = 0; i < 16; i++) {
        if (tabpar[i].par_pos.x >= 1920)
            tabpar[i].par_pos.x = -1920;
        sfSprite_setPosition(tabpar[i].S_parallax, tabpar[i].par_pos);
    }
    return (0);
}