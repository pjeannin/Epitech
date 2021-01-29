/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clic_button
*/

#include "my_defender.h"

int button_is_clic(sfEvent event, button_t *button)
{
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= button->position.x
        && event.mouseButton.x <= (button->position.x + button->size.x)
        && event.mouseButton.y >= button->position.y
        && event.mouseButton.y <= (button->position.y + button->size.y))
            return (1);
    }
    return (0);
}

int button_sprite_is_clic(sfEvent event, button_sprite_t *button)
{
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= button->position.x
        && event.mouseButton.x <= (button->position.x + button->size.x)
        && event.mouseButton.y >= button->position.y 
        && event.mouseButton.y <= (button->position.y + button->size.y))
            return (1);
    }
    return (0);
}