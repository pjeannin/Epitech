/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** map_size
*/

#include "map.h"

unsigned int map_get_size(map_t map)
{
    return (list_get_size(map));
}

bool map_is_empty(map_t map)
{
    return (list_is_empty(map));
}