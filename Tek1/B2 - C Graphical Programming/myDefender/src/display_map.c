/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_map
*/

#include "my_defender.h"

void display_map(sprite_list_t *map, sfRenderWindow *window)
{
    map = move_beginning(map);
    while (map->next) {
        sfRenderWindow_drawSprite(window,
        map->sprite->sprite, sfFalse);
        map = map->next;
    }
    sfRenderWindow_drawSprite(window,
    map->sprite->sprite, sfFalse);
}