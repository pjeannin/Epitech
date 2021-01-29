/*
** EPITECH PROJECT, 2020
** minishell.c
** File description:
** minishell
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minishell.h"

void catchc(int sig)
{
    put_str("\n");
    put_str(PROMPT);
}

int minishell(env_t **env_list)
{
    char *read_val = malloc(sizeof(char));
    size_t n = 0;
    int ret = 0;
    int len;
    char buf[256];

    read_val[0] = '\0';
    while (1) {
        signal(SIGINT,  catchc);
        put_str(PROMPT);
        while (read_val[0] == '\0')
            if ((len = getline(&read_val, &n, stdin)) == -1)
                return (0);
        read_val[len - 1] = '\0';
        ret = get_command(clean_cmd(read_val), env_list);
        if (ret != IGNORE_EXIT)
            return (ret);
        read_val[0] = '\0';
    }
}