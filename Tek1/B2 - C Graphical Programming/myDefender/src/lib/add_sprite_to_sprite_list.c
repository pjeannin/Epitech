/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_sprite_to_sprite_list
*/

#include "image.h"

sprite_list_t *add_sprite_to_sprite_list(sprite_list_t *sprite_list,
char *filepath, int i, int j)
{
    if (sprite_list->sprite != NULL) {
        sprite_list->next = init_sprite_list();
        sprite_list->next->prev = sprite_list;
        sprite_list = sprite_list->next;
    }
    sprite_list->sprite = init_image(filepath, 0, j * 128, i * 128);
    return (sprite_list);
}