/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** find_start
*/

#include "my.h"

int find_cmd(char **input, char *cmd)
{
    for (int i = 0; input[i]; ++i) {
        if (!my_strcmp(cmd, input[i]) && input[i + 1])
            return (i + 1);
        else if (!my_strlen(input[i]))
            return (-1);
    }
    return (-1);
}