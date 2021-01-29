/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_sprite_list.c
*/

#include "image.h"

sprite_list_t *init_sprite_list(void)
{
    sprite_list_t *sprite_list = malloc(sizeof(sprite_list_t));

    if (sprite_list == NULL)
        return (NULL);
    if (!sprite_list)
        return (NULL);
    sprite_list->next = NULL;
    sprite_list->prev = NULL;
    sprite_list->sprite = NULL;
    return (sprite_list);
}