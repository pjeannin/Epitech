/*
** EPITECH PROJECT, 2020
** get_arg.c
** File description:
** my_exec
*/

#include <unistd.h>
#include "my_exec.h"

char **get_arg(char *arg)
{
    char **argv = malloc(sizeof(char) * str_len(arg));
    int i = 0;
    int index = 0;
    int j = 0;

    argv[index] = NULL;
    for (i = 0; arg[i] && arg[i] != ' '; ++i);
    if (arg[i] == '\0')
        return (argv);
    ++index;
    ++i;
    argv[index] = malloc(sizeof(char) * str_len(arg));
    for (i; arg[i]; ++i) {
        if (arg[i] == ' ') {
            ++i;
            argv[index][j] = '\0';
            j = 0;
            printf("%s\n\n", argv[index]);
            ++index;
            argv[index] = malloc(sizeof(char) * (str_len(arg) - i));
        }
        argv[index][j] = arg[i];
        ++j;
    }
    ++index;
    argv[index] = NULL;
    printf("voila le 1 %s\n", argv[1]);
    return (argv);
}