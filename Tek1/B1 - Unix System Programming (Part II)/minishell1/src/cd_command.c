/*
** EPITECH PROJECT, 2020
** cd_command.c
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void change_env(env_t **env_list)
{
    char *curdir = malloc(sizeof(char) * 100);

    (*env_list) = move_beginning(*env_list);
    while (comp_str("OLDPWD", (*env_list)->name))
        (*env_list) = (*env_list)->next;
    (*env_list)->value = find_val(env_list, "PWD");
    (*env_list) = move_beginning(*env_list);
    while (comp_str("PWD", (*env_list)->name))
        (*env_list) = (*env_list)->next;
    getcwd(curdir, 100);
    (*env_list)->value = curdir;
}

char *create_buf(char *command, env_t **env_list)
{
    char *buf = malloc(sizeof(char) * str_len(&command[3]));

    for (int i = 0; i < str_len(&command[3]); ++i) {
        buf[i] = command[i + 3];
    }
    buf[str_len(command) - 2] = '\0';
    if (str_len(buf) && buf[0] == '~')
        buf = concat_str(find_val(env_list, "HOME"), &buf[1]);
    return (buf);
}

void cd_command(char *command, env_t **env_list)
{
    int i = 0;
    char *buf = create_buf(command, env_list);
    char *filepath = malloc(sizeof(char) * 100);

    (*env_list) = move_beginning(*env_list);
    if (command[2] == ' ') {
        if (chdir(buf) == -1) {
            put_error_str(buf);
            put_error_str(": No such a file or directory.\n");
            return;
        }
        change_env(env_list);
    } else if (command[2] == '\0') {
        while (is_root(env_list))
            chdir("..");
        change_env(env_list);
    }
    else
        exe_command(command, env_list);
}