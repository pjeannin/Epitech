/*
** EPITECH PROJECT, 2020
** transform_env.c
** File description:
** minishell 1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char *find_name(char *str)
{
    int index = 0;
    char *ret = malloc(sizeof(char) * str_len(str));

    for (int i = 0; str[i] != '='; ++i) {
        ret[i] = str[i];
        ++index;
    }
    ret[index] = '\0';
    return (ret);
}

char *find_content(char *str)
{
    int index = 0;
    int ok = 0;
    char *ret = malloc(sizeof(char) *str_len(str));

    for (int i = 0; str[i]; ++i) {
        if (ok) {
            ret[index] = str[i];
            ++index;
        }
        if (str[i] == '=')
            ++ok;
    }
    ret[index] = '\0';
    return (ret);
}

env_t *transform_env(char **envp)
{
    env_t *list = malloc(sizeof(env_t));

    list->prev = NULL;
    list->next = NULL;
    list->name = find_name(envp[0]);
    list->value = find_content(envp[0]);
    for (int i = 1; envp[i]; ++i) {
        list->next = malloc(sizeof(env_t));
        list->next->prev = list;
        list = list->next;
        list->next = NULL;
        list->name = find_name(envp[i]);
        list->value = find_content(envp[i]);
    }
    return (move_beginning(list));
}