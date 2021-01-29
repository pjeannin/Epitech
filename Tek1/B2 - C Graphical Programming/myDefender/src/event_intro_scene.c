/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_intro_scene
*/

#include "my_defender.h"

void event_intro_scene(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event))
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            defender->current_scene = 1;
}