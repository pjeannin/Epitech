/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_pause_scene
*/

#include "my_defender.h"

int event_pause_scene_end(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->restart_button)) {
        if ((defender->defense_list = create_empty_defense_list()) == NULL)
            return (1);
        if ((defender->ennemy_list = create_empty_ennemy_list()) == NULL)
            return (1);
        if ((defender->projectil_list = create_empty_projectil_list()) == NULL)
            return (1);
        defender->money = 2;
        defender->score = 0;
        defender->current_scene = 4;
    }
    if (button_is_clic(event, defender->button_list->resume_button))
        defender->current_scene = 4;
    return (0);
}

void event_pause_scene(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        if (button_sprite_is_clic(event, defender->button_list->pause))
            defender->current_scene = 4;
        event_pause_scene_end(defender, event);
        if (button_is_clic(event, defender->button_list->main_menu_button))
            defender->current_scene = 1;
    }
}