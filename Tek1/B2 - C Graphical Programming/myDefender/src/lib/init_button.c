/*
** EPITECH PROJECT, 2020
** init_button.c
** File description:
** init_button
*/

#include "my_defender.h"

button_t *init_button(sfVector2f position, sfVector2f size, sfColor color)
{
    button_t *return_val = malloc(sizeof(button_t));

    if (return_val == NULL)
        return (NULL);
    return_val->button = sfRectangleShape_create();
    sfRectangleShape_setPosition(return_val->button, position);
    sfRectangleShape_setSize(return_val->button, size);
    sfRectangleShape_setOutlineColor(return_val->button, color);
    sfRectangleShape_setFillColor(return_val->button, color);
    return_val->size = size;
    return_val->position = position;
    return (return_val);
}

button_sprite_t *init_sprite_button(sfVector2f position, sfVector2f size,
char *filepath)
{
    button_sprite_t *return_val = malloc(sizeof(button_sprite_t));

    if (return_val == NULL)
        return (NULL);
    return_val->button = init_image(filepath, 0, position.x, position.y);
    return_val->size = size;
    return_val->position = position;
    return (return_val);
}