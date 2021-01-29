/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move_end
*/

#include "image.h"

sprite_list_t *move_beginning(sprite_list_t *list)
{
    while (list->prev)
        list = list->prev;
    return (list);
}

sprite_list_t *move_end(sprite_list_t *list)
{
    while (list->next)
        list = list->next;
    return (list);
}