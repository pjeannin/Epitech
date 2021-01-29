/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_main_menu_scene
*/

#include "my_defender.h"

void event_main_menu_scene_end(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->play_button))
        defender->current_scene = 3;
    if (button_is_clic(event, defender->button_list->rules_button))
        defender->current_scene = 2;
}

void event_main_menu_scene(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        event_main_menu_scene_end(defender, event);
    }
}