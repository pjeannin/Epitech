/*
** EPITECH PROJECT, 2020
** disp_bis.c
** File description:
** disp_bis
*/

#include <unistd.h>
#include "my_ls.h"

void dis_spaces(file_t *list, int print, int longer)
{
    while (print + str_len(list->name) != longer 
    & list->prev->name[0] != '.') {
        write(1, " ", 1);
        ++print;
    }
}

void display_r(file_t *list)
{
    int longer = find_longer(list);
    int print;

    list = move_end(list);
    if (list->name == NULL)
        return;
    while (list) {
        if (list->name[0] != '.') {
            print = 0;
            write(1, list->name, str_len(list->name));
            dis_spaces(list, print, longer);
        }
        list = list->prev;
    }
    write(1, "\n", 1);
}

void add_f(file_t *list, int print)
{
    if (list->right[0] == 'd') {
        write(1, "/", 1);
        ++print;
    } else if (list->right[3] == 'x' || list->right[6] == 'x'
    || list->right[9] == 'x') {
        write(1, "*", 1);
        ++print;
    }
}

void display_F(file_t *list)
{
    int longer = find_longer(list);
    int print;

    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        print = 0;
        if (list->name[0] != '.') {
            write(1, list->name, str_len(list->name));
            add_f(list, print);
            dis_spaces(list, print, longer);
        }
        list = list->next;
    }
    write(1, "\n", 1);
}

void display_lF(file_t *list)
{
    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        if (list->name[0] != '.')
            dis_all_F(list);
        list = list->next;
    }
}