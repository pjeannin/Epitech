/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

static void press_echap_end(window_t *win)
{
    if (win->vec.x >= 695 && win->vec.x <= 1176 &&
    win->vec.y >= 651 && win->vec.y <= 834) {
        sfMusic_pause(win->music);
        sfRenderWindow_close(win->window);
    }
}

int press_echap(window_t *win)
{
    win->vec = sfMouse_getPositionRenderWindow(win->window);

    if (win->event.type == sfEvtMouseButtonReleased) {
        if (win->vec.x >= 695 && win->vec.x <= 1176 &&
            win->vec.y >= 176 && win->vec.y <= 361)
            win->echap_switch = 0;
        else if (win->vec.x >= 695 && win->vec.x <= 1176 &&
            win->vec.y >= 413 && win->vec.y <= 598) {
            win->echap_switch = 0;
            win->screen = 1;
            }
        else
            press_echap_end(win);
    }
    anime_echap(win);
    return (0);
}

int init_texture_echap(void)
{
    tabgame[0].T_menugame =
    sfTexture_createFromFile("./ressources/menu/resume1.png", NULL);
    tabgame[1].T_menugame =
    sfTexture_createFromFile("./ressources/menu/menu1.png", NULL);
    tabgame[2].T_menugame =
    sfTexture_createFromFile("./ressources/menu/quit1.png", NULL);
    tabgame[3].T_menugame =
    sfTexture_createFromFile("./ressources/menu/game_menu.png", NULL);
    return (0);
}

int init_echap(void)
{
    tabgame = malloc(sizeof(menugame_t) * 4);

    for (int i = 0; i < 4; i++)
        tabgame[i].S_menugame = sfSprite_create();
    init_texture_echap();
    for (int i = 0; i < 4; i++)
        sfSprite_setTexture(tabgame[i].S_menugame,
        tabgame[i].T_menugame, sfTrue);
    base_pos_echap();
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(tabgame[i].S_menugame, tabgame[i].menugame_pos);
    return (0);
}