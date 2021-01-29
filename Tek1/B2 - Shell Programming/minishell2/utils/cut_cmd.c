/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cut_pipe_cmd
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char **cut_cmd(char *command, char sep)
{
    char ** cmd_cut = malloc(sizeof(char *) * str_len(command));
    int index = 0;
    int line_index = 0;

    for (int i = 0; i < str_len(command); ++i)
        cmd_cut[i] = NULL;
    for (int i = 0; command[i]; ++i) {
        cmd_cut[index] = malloc(sizeof(char) * str_len(command));
        for (; command[i + 1] && command[i + 1] != sep; ++i)
            cmd_cut[index][line_index++] = command[i];
        if (command[i + 1] == '\0')
            cmd_cut[index][line_index] = command[i];
        i += 2;
        ++index;
        line_index = 0;
    }
    return (cmd_cut);
}