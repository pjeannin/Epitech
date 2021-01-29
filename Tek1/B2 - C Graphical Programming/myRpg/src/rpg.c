/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

int init_rpg(charact_t *charact, window_t *win, game_t *game_struct)
{
    init_music(win);
    init_end(game_struct);
    init_frame_buffer(game_struct);
    init_stats(game_struct);
    init_map(game_struct);
    init_quete(game_struct);
    init_object_list(game_struct);
    init_guardian(game_struct);
    init_window(win);
    init_menu(game_struct);
    init_charact(charact);
    init_boss(game_struct);
    return (0);
}

void clock_in_game(game_t *game_struct, charact_t *charact)
{
    anime_charact(charact);
    move_map(game_struct);
    move_guardian(game_struct);
    set_string(game_struct);
}

void handle_screen(window_t *win, game_t *game_struct, charact_t *charact)
{
    if (win->screen == 1)
        parallax();
    else if ((win->screen == 2 || win->screen > 6) && !win->echap_switch)
        clock_in_game(game_struct, charact);
    else
        end_menu(game_struct, win);
}

int rpg(game_t *game_struct)
{
    window_t win;
    charact_t charact;

    win.echap_switch = 0;
    init_rpg(&charact, &win, game_struct);
    while (sfRenderWindow_isOpen(win.window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(win.clock))
        > 1000 / 30) {
            sfRenderWindow_clear(win.window, sfBlack);
            sfClock_restart(win.clock);
            handle_screen(&win, game_struct, &charact);
            play(&win, &charact, game_struct);
            window_event(&win, &charact, game_struct);
            sfRenderWindow_display(win.window);
        }
    }
    sfMusic_destroy(win.music);
    sfRenderWindow_destroy(win.window);
    return (0);
}