/*
** EPITECH PROJECT, 2020
** dis_all_f.c
** File description:
** my_ls
*/

#include "my_ls.h"

void dis_all(file_t *list)
{
    int len_link = f_len_link(list);
    int len_owner = f_len_owner(list);
    int len_grp = f_len_grp(list);
    int len_size = f_len_size(list);

    write(1, list->right, str_len(list->right));
    dis_elem(char_from_int(list->link), len_link);
    dis_elem(list->owner, len_owner);
    dis_elem(list->group, len_grp);
    dis_elem(char_from_int(list->size), len_size);
    dis_elem(list->m_time, 13);
    write(1, " ", 1);
    write(1, list->name, str_len(list->name));
    write(1, "\n", 1);
}

void dis_all_F(file_t *list)
{
    int len_link = f_len_link(list);
    int len_owner = f_len_owner(list);
    int len_grp = f_len_grp(list);
    int len_size = f_len_size(list);

    write(1, list->right, str_len(list->right));
    dis_elem(char_from_int(list->link), len_link);
    dis_elem(list->owner, len_owner);
    dis_elem(list->group, len_grp);
    dis_elem(char_from_int(list->size), len_size);
    dis_elem(list->m_time, 13);
    write(1, " ", 1);
    write(1, list->name, str_len(list->name));
    if (list->right[0] == 'd')
        write(1, "/", 1);
    else if (list->right[3] == 'x' || list->right[6] == 'x' || list->right[9] == 'x')
        write(1, "*", 1);
    write(1, "\n", 1);
}