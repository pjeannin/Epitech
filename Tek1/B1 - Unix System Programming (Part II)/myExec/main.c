/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** my_exec
*/

#include "my_exec.h"

int main(int ac, char **av)
{
    char **newargv = get_arg(av[1]);
    char **newenv;
    char *execname = get_exec_name(av[1]);

    for (int i = 1; newargv[i]; ++i)
        printf("%s\n", newargv[i]);
    return (0);
}