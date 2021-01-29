/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** my_list
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "my_ls.h"

file_t *init_list(void)
{
    file_t *list = malloc(sizeof(file_t));

    list->name = NULL;
    list->next = NULL;
    list->prev = NULL;
    list->right = malloc(sizeof(char) * 11);
    for (int i = 0; i < 10; ++i)
        list->right[i] = '-';
    list->right[10] = '\0';
    return (list);
}

file_t *move_end(file_t *list)
{
    while (list->next)
        list = list->next;
    return (list);
}

file_t *move_beginning(file_t *list)
{
    while (list->prev)
        list = list->prev;
    return (list);
}

void fill_right(int mode, file_t *list)
{
    switch (mode % 8) {
        case 7: {
            list->right[7] = 'r';
            list->right[8] = 'w';
            list->right[9] = 'x';
            break;
        } case 6: {
            list->right[7] = 'r';
            list->right[8] = 'w';
            list->right[9] = '-';
            break;
        } case 5:  {
            list->right[7] = 'r';
            list->right[8] = '-';
            list->right[9] = 'x';
            break;
        } case 4 : {
            list->right[7] = 'r';
            list->right[8] = '-';
            list->right[9] = '-';
            break;
        } case 2: {
            list->right[7] = '-';
            list->right[8] = 'w';
            list->right[9] = '-';
            break;
        } case 1: {
            list->right[7] = '-';
            list->right[8] = '-';
            list->right[9] = 'x';
            break;
        }
    }
    mode /= 8;
    switch (mode % 8) {
        case 7: {
            list->right[4] = 'r';
            list->right[5] = 'w';
            list->right[6] = 'x';
            break;
        } case 6: {
            list->right[4] = 'r';
            list->right[5] = 'w';
            list->right[6] = '-';
            break;
        } case 5:  {
            list->right[4] = 'r';
            list->right[5] = '-';
            list->right[6] = 'x';
            break;
        } case 4 : {
            list->right[4] = 'r';
            list->right[5] = '-';
            list->right[6] = '-';
            break;
        } case 2: {
            list->right[4] = '-';
            list->right[5] = 'w';
            list->right[6] = '-';
            break;
        } case 1: {
            list->right[4] = '-';
            list->right[5] = '-';
            list->right[6] = 'x';
            break;
        }
    }
    mode /= 8;
    switch (mode % 8) {
        case 7: {
            list->right[1] = 'r';
            list->right[2] = 'w';
            list->right[3] = 'x';
            break;
        } case 6: {
            list->right[1] = 'r';
            list->right[2] = 'w';
            list->right[3] = '-';
            break;
        } case 5:  {
            list->right[1] = 'r';
            list->right[2] = '-';
            list->right[3] = 'x';
            break;
        } case 4 : {
            list->right[1] = 'r';
            list->right[2] = '-';
            list->right[3] = '-';
            break;
        } case 2: {
            list->right[1] = '-';
            list->right[2] = 'w';
            list->right[3] = '-';
            break;
        } case 1: {
            list->right[1] = '-';
            list->right[2] = '-';
            list->right[3] = 'x';
            break;
        }
    }
}