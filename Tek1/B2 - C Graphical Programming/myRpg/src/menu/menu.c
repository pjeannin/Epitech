/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

void play_clock(window_t *win, charact_t *charact, game_t *game_struct)
{
    win->time = sfClock_getElapsedTime(win->clock);
    win->seconds = win->time.microseconds / 10000.0;
    if (win->seconds > 1/20 && win->echap_switch == 0) {
        sfClock_restart(win->clock);
        if (win->screen == 1)
            parallax();
        if (win->screen == 2) {
            anime_charact(charact);
            move_map(game_struct);
            move_guardian(game_struct);
        }
    }
}

void check_key_play(window_t *win, game_t *game_struct, charact_t *charact)
{
    if (win->event.key.type == sfEvtKeyPressed) {
        init_rpg(charact, win, game_struct);
        win->screen = 2;
    }
}

int window_event(window_t *win, charact_t *charact, game_t *game_struct)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->h_play == 1)
            check_key_play(win, game_struct, charact);
        end_event(win, game_struct);
        if (win->screen == 1 && win->h_play == 0)
            check_button(win);
        if (win->screen == 2 || win->screen > 6) {
            check_key_caract(win, charact, game_struct);
            check_key_echap(win);
            check_key_take_object(win, charact, game_struct);
            check_key_inventory(win);
            player_damage(game_struct, charact, win);
            give_life_back(game_struct, win);
        }
    }
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    return (0);
}

void init_menu(game_t *game_struct)
{
    init_parallax();
    init_button();
    init_echap();
    init_inventory(game_struct);
}

int menu(window_t *win)
{
    draw_menu(win);
    return (0);
}