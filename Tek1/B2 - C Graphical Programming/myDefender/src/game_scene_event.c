/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game__scene_event
*/

#include "my_defender.h"

void game_scene_event_mid(defender_t *defender, sfEvent event, int *new_defense)
{
    if (button_sprite_is_clic(event, defender->button_list->defense2) &&
    defender->money >= 2)
        *new_defense = 2;
    if (button_sprite_is_clic(event, defender->button_list->pause))
        defender->current_scene = 6;
}

int game_scene_event(defender_t *defender)
{
    sfEvent event;
    static int new_defense = 0;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        if (button_sprite_is_clic(event, defender->button_list->defense1) &&
        defender->money >= 1)
            new_defense = 1;
        game_scene_event_mid(defender, event, &new_defense);
        if (new_defense)
            add_defense_animation(event, new_defense, defender);
        if (new_defense && event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
            if (new_defense = add_defense(new_defense, defender,
            create_sfvector2f(event.mouseButton.x, event.mouseButton.y)))
                return (1);
        }
    }
    return (0);
}