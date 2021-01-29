/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "my_rpg.h"

int init_music(window_t *win)
{
    win->music = sfMusic_createFromFile("./ressources/music/dreaming.ogg");
    sfMusic_play(win->music);
    return (0);
}

int init_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 30};
    win->window = sfRenderWindow_create(mode, "My RPG", sfClose, NULL);
    win->clock = sfClock_create();
    win->screen = 1;
    win->choice_echap = 0;
    win->dis_invent = 0;
    win->choice = 0;
    win->h_play = 0;
    win->echap_switch = 0;
    win->die = 0;
    return (0);
}

int play(window_t *win, charact_t *charact, game_t *game_struct)
{
    if (win->screen == 1)
        menu(win);
    if (win->screen == 2 || win->screen > 6) {
        sfMusic_stop(win->music);
        play_game(win, charact, game_struct);
    }
    return (0);
}

int main(int ac, char **av)
{
    game_t *game_struct = malloc(sizeof(game_t));

    if (ac != 1) {
        write(2, NEED_NO_ARGS, my_strlen(NEED_NO_ARGS));
        return (84);
    }
    if (rpg(game_struct) < 0) {
        write(2, RPG_ERROR, my_strlen(RPG_ERROR));
    }
    free_rpg(game_struct);
    return (0);
}