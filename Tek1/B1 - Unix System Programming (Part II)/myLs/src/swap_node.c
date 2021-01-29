/*
** EPITECH PROJECT, 2020
** swap_node.c
** File description:
** my_ls
*/

#include "my_ls.h"

void swap_char(char **s1, char **s2)
{
    char *tmp = *s1;

    *s1 = *s2;
    *s2 = tmp;
}

void swap_int(int *i1, int *i2)
{
    int tmp = *i1;

    *i1 = *i2;
    *i2 = tmp;
}

file_t *swap_node(file_t *list)
{
    swap_char(&list->name, &list->next->name);
    swap_char(&list->right, &list->next->right);
    swap_char(&list->a_time, &list->next->a_time);
    swap_char(&list->m_time, &list->next->m_time);
    swap_char(&list->owner, &list->next->owner);
    swap_char(&list->group, &list->next->group);
    swap_int(&list->type, &list->next->type);
    swap_int(&list->size, &list->next->size);
    swap_int(&list->link, &list->next->link);
    return (list);
}