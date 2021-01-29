/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_score_scene
*/

#include "my_defender.h"

int event_score_scene_end(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->play_again_button)) {
        if ((defender->ennemy_list = create_empty_ennemy_list()) == NULL)
            return (1);
        if ((defender->defense_list = create_empty_defense_list()) == NULL)
            return (1);
        if ((defender->projectil_list = create_empty_projectil_list()) == NULL)
            return (1);
        defender->castle->health = defender->castle->init_health;
        defender->money = 2;
        defender-> current_scene = 4;
        defender->high_score = (defender->high_score < defender->score) ?
        defender->score : defender->high_score;
        defender->score = 0;
    }
    return (0);
}

void event_score_scene(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        if (button_is_clic(event, defender->button_list->menu_button)) {
            defender->high_score = (defender->high_score < defender->score) ?
            defender->score : defender->high_score;
            defender-> current_scene = 1;
        }
        event_score_scene_end(defender, event);
    }
}