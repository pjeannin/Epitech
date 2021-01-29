/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

void base_pos_but(void)
{
    but[0].but_pos.x = 1450/2;
    but[0].but_pos.y = 1150/2;
    but[1].but_pos.x = 1450/2;
    but[1].but_pos.y = 1150/2;
    but[2].but_pos.x = 1450/2;
    but[2].but_pos.y = 1550/2;
    but[3].but_pos.x = 1450/2;
    but[3].but_pos.y = 1550/2;
    but[4].but_pos.x = 425;
    but[4].but_pos.y = 100;
    but[0].but_scale.x = 0.8;
    but[0].but_scale.y = 0.8;
    but[1].but_scale.x = 0.8;
    but[1].but_scale.y = 0.8;
    but[2].but_scale.x = 0.8;
    but[2].but_scale.y = 0.8;
    but[3].but_scale.x = 0.8;
    but[3].but_scale.y = 0.8;
    but[4].but_scale.x = 1;
    but[4].but_scale.y = 1;
}

int init_texture_but(void)
{
    but[0].T_button =
    sfTexture_createFromFile("./ressources/menu/but_play1.png", NULL);
    but[1].T_button =
    sfTexture_createFromFile("./ressources/menu/but_play2.png", NULL);
    but[2].T_button =
    sfTexture_createFromFile("./ressources/menu/but_quit1.png", NULL);
    but[3].T_button =
    sfTexture_createFromFile("./ressources/menu/but_quit2.png", NULL);
    but[4].T_button =
    sfTexture_createFromFile("./ressources/menu/thief_logo.png", NULL);
    but[5].T_button =
    sfTexture_createFromFile("./ressources/menu/how_to_play.png", NULL);
    but[6].T_button =
    sfTexture_createFromFile("./ressources/menu/astuce.png", NULL);
    return (0);
}

int check_key_inventory(window_t *win)
{
    if (win->dis_invent == 1) {
        if (win->event.key.code == sfKeyI && win->event.key.type ==
        sfEvtKeyPressed)
            win->dis_invent = 0;
    }
    else if (win->event.key.code == sfKeyI && win->event.key.type ==
    sfEvtKeyPressed)
        win->dis_invent = 1;
    return (0);
}

void check_button(window_t *win)
{
    win->vec = sfMouse_getPositionRenderWindow(win->window);

    if (win->event.type == sfEvtMouseButtonReleased) {
        if (win->vec.x >= 725 && win->vec.x <= 1092 &&
            win->vec.y >= 578 && win->vec.y <= 730)
            win->h_play = 1;
        if (win->vec.x >= 725 && win->vec.x <= 1092 &&
            win->vec.y >= 777 && win->vec.y <= 932)
            sfRenderWindow_close(win->window);
    }
    check_button_end(win);
}

int init_button(void)
{
    but = malloc(sizeof(button_t) * 7);

    for (int i = 0; i < 7; i++)
        but[i].S_button = sfSprite_create();
    init_texture_but();
    base_pos_but();
    for (int i = 0; i < 5; i++) {
        sfSprite_setTexture(but[i].S_button, but[i].T_button, sfTrue);
        sfSprite_setPosition(but[i].S_button, but[i].but_pos);
        sfSprite_setScale(but[i].S_button, but[i].but_scale);
    }
    but[5].but_pos.x = 600;
    but[5].but_pos.y = 200;
    but[6].but_pos.x = 650;
    but[6].but_pos.y = 750;
    sfSprite_setTexture(but[5].S_button, but[5].T_button, sfTrue);
    sfSprite_setPosition(but[5].S_button, but[5].but_pos);
    sfSprite_setTexture(but[6].S_button, but[6].T_button, sfTrue);
    sfSprite_setPosition(but[6].S_button, but[6].but_pos);
    return (0);
}