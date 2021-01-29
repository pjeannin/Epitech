/*
** EPITECH PROJECT, 2020
** get_exec_name.
** File description:
** my_exec
*/

#include <stdlib.h>
#include "my_exec.h"

char *get_exec_name(char *arg)
{
    char *exe_name = malloc(sizeof(char) * str_len(arg));
    int i;

    for (i = 0; arg[i] && arg[i] != ' '; ++i)
        exe_name[i] = arg[i];
    exe_name[i] = '\0';
    return (exe_name);
}