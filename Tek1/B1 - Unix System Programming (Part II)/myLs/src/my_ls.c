/*
** EPITECH PROJECT, 2020
** my_ls.c
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

void free_list(file_t *list)
{
    while (list->next) {
        list = list->next;
        free(list->prev);
    }
    free(list);
}

DIR *open_dir(char *dirname)
{
    DIR *directory = opendir(dirname);

    if (directory == NULL) {
        write(2, "./my_ls: ", 9);
        write(2, dirname, str_len(dirname));
        write(2, ": No such file or directory\n", 28);
        exit (84);
    }
    return (directory);
}

void my_ls(int ac, char **av, char *dirname)
{
    DIR *directory;
    char *filename;
    struct dirent *file_read;
    struct stat file;
    file_t *list = init_list();

    directory = open_dir(dirname);
    file_read = readdir(directory);
    while (file_read) {
        list = fill_list(list, dirname, file_read, file);
        file_read = readdir(directory);
    }
    list = sort(list);
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0')
        disp_R(list, dirname);
    check_flags(list, ac, av);
    free_list(move_beginning(list));
}