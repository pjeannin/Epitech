/*
** EPITECH PROJECT, 2020
** comp_str.c
** File description:
** my_ls
*/

#include <unistd.h>
#include "my_ls.h"

void display_lsa(file_t *list)
{
    int longer = find_longer(list);
    int print;

    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        print = 0;
        write(1, list->name, str_len(list->name));
        while (print + str_len(list->name) != longer && list->next) {
            write(1, " ", 1);
            ++print;
        }
        list = list->next;
    }
    write(1, "\n", 1);
}

void display_la(file_t *list)
{
    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        dis_all(list);
        list = list->next;
    }
}

void display_l(file_t *list)
{
    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        if (list->name[0] != '.')
            dis_all(list);
        list = list->next;
    }
}

void display_d(file_t *list)
{
    int longer = find_longer(list);
    int print;

    list = move_beginning(list);
    if (list->name == NULL)
        return;
    while (list) {
        print = 0;
        if (list->right[0] == 'd') {
            write(1, list->name, str_len(list->name));
            while (print + str_len(list->name) != longer && list->next) {
                write(1, " ", 1);
                ++print;
            }
        }
        list = list->next;
    }
    write(1, "\n", 1);
}

void display_ls(file_t *list)
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
            while (print + str_len(list->name) != longer && list->next) {
                write(1, " ", 1);
                ++print;
            }
        }
        list = list->next;
    }
    write(1, "\n", 1);
}