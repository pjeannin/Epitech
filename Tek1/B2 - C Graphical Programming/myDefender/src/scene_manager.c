/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** scene_manager
*/

#include "my_defender.h"

void load_scene_end(defender_t *defender)
{
    switch (defender->current_scene) {
        case 4:
            game_scene(defender);
            break;
        case 5:
            score_scene(defender);
            break;
        case 6:
            pause_scene(defender);
            break;
        default:
            break;
    }
}

void load_scene(defender_t *defender)
{
    switch (defender->current_scene) {
        case 0:
            intro_scene(defender);
            break;
        case 1:
            main_menu_scene(defender);
            break;
        case 2:
            rules_scene(defender);
            break;
        case 3:
            level_scene(defender);
            break;
        default:
            load_scene_end(defender);
            break;
    }
}

void scene_manager(defender_t *defender)
{
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(defender->window)) {
        sfRenderWindow_clear(defender->window, sfBlack);
        while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 1000 / 30);
        sfClock_restart(clock);
        load_scene(defender);
        draw_exit_button(defender, defender->window);
        sfRenderWindow_display(defender->window);
    }
}