/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

void init_die(void)
{
    tabinvent[7].S_invent = sfSprite_create();
    tabinvent[7].T_invent =
    sfTexture_createFromFile("./ressources/menu/mort.png", NULL);
    sfSprite_setTexture(tabinvent[7].S_invent, tabinvent[7].T_invent, sfTrue);
    tabinvent[7].invent_pos.x = 0;
    tabinvent[7].invent_pos.y = 200;
    sfSprite_setPosition(tabinvent[7].S_invent, tabinvent[7].invent_pos);
}

void init_heart(void)
{
    tabinvent[8].S_invent = sfSprite_create();
    tabinvent[8].T_invent =
    sfTexture_createFromFile("./ressources/menu/heart.png", NULL);
    sfSprite_setTexture(tabinvent[8].S_invent, tabinvent[8].T_invent, sfTrue);
    tabinvent[8].invent_pos.x = 1830;
    tabinvent[8].invent_pos.y = 35;
    sfSprite_setPosition(tabinvent[8].S_invent, tabinvent[8].invent_pos);
}

void draw_menu(window_t *win)
{
    for (int i = 0; i < 16; i++)
        sfRenderWindow_drawSprite(win->window, tabpar[i].S_parallax, NULL);
    if (win->choice == 1)
        sfRenderWindow_drawSprite(win->window, but[1].S_button, NULL);
    else
        sfRenderWindow_drawSprite(win->window, but[0].S_button, NULL);
    if (win->choice == 3)
        sfRenderWindow_drawSprite(win->window, but[3].S_button, NULL);
    else
        sfRenderWindow_drawSprite(win->window, but[2].S_button, NULL);
    sfRenderWindow_drawSprite(win->window, but[4].S_button, NULL);
    if (win->h_play == 1) {
        sfRenderWindow_drawSprite(win->window, but[5].S_button, NULL);
        sfRenderWindow_drawSprite(win->window, but[6].S_button, NULL);
    }
}