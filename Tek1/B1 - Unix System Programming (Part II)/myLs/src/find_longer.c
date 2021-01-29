/*
** EPITECH PROJECT, 2020
** find_loner.c
** File description:
** my_ls
*/

#include "my_ls.h"

int find_longer(file_t *list)
{
    int longer = 0;

    list = move_beginning(list);
    while (list->next->next) {
        if (str_len(list->name) > longer)
            longer = str_len(list->name);
        list = list->next;
    }
    longer += 4;
    while (longer % 4)
        ++longer;
    return (longer);
}