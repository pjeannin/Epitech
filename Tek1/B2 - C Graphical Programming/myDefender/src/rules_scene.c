/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rules_scene
*/

#include "my_defender.h"

void event_rules_scene(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            defender->current_scene = 1;
    }
}

void rules_scene(defender_t *defender)
{
    picture_t *pic = init_image("PNG/rules.png", 0, 0, 0);

    sfRenderWindow_drawSprite(defender->window, pic->sprite, sfFalse);
    event_rules_scene(defender);
}