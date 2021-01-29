/*
** EPITECH PROJECT, 2020
** fill_list.c
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
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "my_ls.h"

int find_type(int mode)
{
    switch (mode & S_IFMT) {
        case S_IFREG:
            return (1);
    }
}

file_t *fill_end_list(file_t *list, struct stat file)
{
    struct passwd *name;
    struct group *grp;

    if ((file.st_mode & S_IFMT) == S_IFDIR)
        list->right[0] = 'd';
    else
        list->right[0] = '-';
    fill_right(file.st_mode, list);
    list->size = file.st_size;
    name = getpwuid(file.st_uid);
    list->owner = name->pw_name;
    grp = getgrgid(file.st_gid);
    list->group = grp->gr_name;
    list->type = find_type(file.st_mode);
    list->link = file.st_nlink;
    list->a_time_brut = ctime((const time_t *)&file.st_atime);
    list->m_time_brut = ctime((const time_t *)&file.st_mtime);
    list->m_time = convert_time(ctime((const time_t *)&file.st_mtime));
    list->a_time = convert_time(ctime((const time_t *)&file.st_atime));
    return (list);
}

file_t *fill_list(file_t *list, char *dirname, struct dirent *file_read,
struct stat file)
{
    list = move_end(list);
    if (list->name != NULL) {
        list->next = init_list();
        list->next->prev = list;
        list = list->next;
    }
    if (dirname[0] == '.' && dirname[1] == '\0')
        list->name = file_read->d_name;
    else
        list->name = concat_str(dirname, file_read->d_name);
    list->name = file_read->d_name;
    stat(list->name, &file);
    list = fill_end_list(list, file);
    return (list);
}