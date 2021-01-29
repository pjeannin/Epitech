/*
** EPITECH PROJECT, 2020
** dis_all.
** File description:
** my_ls
*/

#include "my_ls.h"

int f_len_link(file_t *list)
{
    int size = 0;

    list = move_beginning(list);
    while (list) {
        if (str_len(char_from_int(list->link)) > size)
            size = str_len(char_from_int(list->link));
        list = list->next;
    }
    return (size + 2);
}

int f_len_owner(file_t *list)
{
    int size = 0;

    list = move_beginning(list);
    while (list) {
        if (str_len(list->owner) > size)
            size = str_len(list->owner);
        list = list->next;
    }
    return (size + 1);
}

int f_len_grp(file_t *list)
{
    int size = 0;

    list = move_beginning(list);
    while (list) {
        if (str_len(list->group) > size)
            size = str_len(list->group);
        list = list->next;
    }
    return (size + 2);
}

int f_len_size(file_t *list)
{
    int size = 0;

    list = move_beginning(list);
    while (list) {
        if (str_len(char_from_int(list->size)) > size)
            size = str_len(char_from_int(list->size));
        list = list->next;
    }
    return (size + 2);
}

void dis_elem(char *elem, int len)
{
    int print = 0;

    while (str_len(elem) + print < len) {
        write(1, " ", 1);
        ++print;
    }
    write(1, elem, str_len(elem));
}