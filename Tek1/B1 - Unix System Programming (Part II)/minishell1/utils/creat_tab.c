/*
** EPITECH PROJECT, 2020
** creat_tab.c
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int count_cut(char *path)
{
    int cut = 1;

    while (*path++)
        if (*path == ':')
            ++cut;
    return (cut);
}

void fill_tab(char cur, char **tab, int *index_p, int *index_t)
{
    if (cur == ':') {
        *index_p = 0;
        ++(*index_t);
        if ((tab[*index_t] = malloc(sizeof(char) * 30)) == 0) {
            put_error_str("Malloc error\n");
            exit(84);
        }
    } else {
        tab[*index_t][*index_p] = cur;
        ++(*index_p);
    }
}

char **creat_tab(env_t **env_list)
{
    char *path = find_val(env_list, "PATH");
    int cut = count_cut(path);
    char **tab = malloc(sizeof(char *) * cut + 1);
    int index_t = 0;
    int index_p = 0;

    if (tab == 0
    || (tab[index_t] = malloc(sizeof(char) * str_len(path))) == 0) {
        put_error_str("Malloc error\n");
        exit(84);
    }
    for (int i = 0; path[i]; ++i)
        fill_tab(path[i], tab, &index_p, &index_t);
    ++index_t;
    tab[index_t] = NULL;
    return (tab);
}