/*
** EPITECH PROJECT, 2020
** check_col.c
** File description:
** runner
*/

#include "my_runner.h"

int check_col(map_list_t *map, picture_t *mario)
{
    map = move_beginning(map);
    while (map->next) {
        for (int i = 0; i < 200; ++i)
            if ((mario->pos.y + i > map->element->pos.y
            && mario->pos.y + i < map->element->pos.y + 120)
            && (mario->pos.x + 130 > (map->element)->pos.x
            && mario->pos.x < ((map->element)->pos.x + 120))) {
                return (1);
            }
        map = map->next;
    }
    return (0);
}