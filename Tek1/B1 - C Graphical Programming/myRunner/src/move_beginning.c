/*
** EPITECH PROJECT, 2020
** move_beginning.c
** File description:
** runner
*/

#include "my_runner.h"

map_list_t *move_beginning(map_list_t *list)
{
    while (list->prev)
        list = list->prev;
    return (list);
}