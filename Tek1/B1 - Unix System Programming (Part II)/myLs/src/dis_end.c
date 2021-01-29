/*
** EPITECH PROJECT, 2020
** dis_end.c
** File description:
** my_ls
*/

#include "my_ls.h"

void display_laF(file_t *list)
{
    list = move_beginning(list);
    while (list) {
        dis_all_F(list);
        list = list->next;
    }
}

void display_lst(file_t *list)
{
    list = sort_a_time(list);
    display_ls(list);
}

void display_lsat(file_t *list)
{
    list = sort_a_time(list);
    display_lsa(list);
}