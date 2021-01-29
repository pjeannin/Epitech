/*
** EPITECH PROJECT, 2020
** disp_R.c
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "my_ls.h"

file_t *new_dir(file_t *list, char *dirname)
{
    file_t *list2 = init_list();
    DIR *directory = open_dir(concat_str(dirname, list->name));
    struct dirent *file_read = readdir(directory);
    struct stat file;

    while (file_read) {
        list2 = fill_list(list2, concat_str(dirname, list->name), file_read,
        file);
        file_read = readdir(directory);
    }
    list2 = sort(list2);
    return (list2);
}

void disp_R(file_t *list, char *dirname)
{
    DIR *directory;
    char *filename;
    struct dirent *file_read;
    struct stat file;
    file_t *list2;

    display_ls(list);
    list = move_beginning(list);
    while (list) {
        if (list->right[0] == 'd' && list->name[0] != '.') {
            list2 = new_dir(list, dirname);
            write(1, "\n", 1);
            write(1, concat_str(dirname, list->name),
            str_len(concat_str(dirname, list->name)));
            write(1, "\n", 1);
            disp_R(list2, concat_str(dirname, list->name));
        }
        list = list->next;
    }
}