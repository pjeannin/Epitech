/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_key
*/

#include "my_rpg.h"

static void check_end(window_t *win, charact_t *charact, game_t *game_struct)
{
    if (win->event.key.code == sfKeyUp && win->event.key.type ==
    sfEvtKeyPressed) {
        charact->charact_rect.top = 120;
        charact->anim = 1;
        game_struct->map->anim = 4;
    } else if (win->event.key.code == sfKeyUp && win->event.key.type ==
    sfEvtKeyReleased) {
        charact->anim = 0;
        game_struct->map->anim = 0;
    }
}

static void check_mid(window_t *win, charact_t *charact, game_t *game_struct)
{
    if (win->event.key.code == sfKeyRight && win->event.key.type ==
    sfEvtKeyPressed) {
        charact->charact_rect.top = 80;
        charact->anim = 1;
        game_struct->map->anim = 3;
    } else if (win->event.key.code == sfKeyRight && win->event.key.type ==
    sfEvtKeyReleased) {
        charact->anim = 0;
        game_struct->map->anim = 0;
    } else
        check_end(win, charact, game_struct);
}

static void check_start(window_t *win, charact_t *charact, game_t *game_struct)
{
    if (win->event.key.code == sfKeyLeft && win->event.key.type ==
    sfEvtKeyPressed) {
        charact->charact_rect.top = 40;
        charact->anim = 1;
        game_struct->map->anim = 2;
    } else if (win->event.key.code == sfKeyLeft && win->event.key.type ==
    sfEvtKeyReleased) {
        charact->anim = 0;
        game_struct->map->anim = 0;
    } else
        check_mid(win, charact, game_struct);
}

int check_key_caract(window_t *win, charact_t *charact, game_t *game_struct)
{
    if (win->event.key.code == sfKeyDown && win->event.key.type ==
    sfEvtKeyPressed) {
        charact->charact_rect.top = 0;
        charact->anim = 1;
        game_struct->map->anim = 1;
    } else if (win->event.key.code == sfKeyDown && win->event.key.type ==
    sfEvtKeyReleased) {
        charact->anim = 0;
        game_struct->map->anim = 0;
    } else
        check_start(win, charact, game_struct);
    return (0);
}