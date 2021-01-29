/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe_cmd
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "minishell.h"

void simple_pipe(char **cmd_cut, env_t **env_list)
{
    int fd[2];
    int pid;

    pipe(fd);
    pid = fork();
    if (!pid) {
        dup2(fd[1], STDOUT_FILENO);
        get_command(cmd_cut[0], env_list);
        close(fd[0]);
        close(fd[1]);
        exit(0);
    } else {
        wait(NULL);
        pid = fork();
        if (!pid) {
            dup2(fd[0], STDIN_FILENO);
            get_command(cmd_cut[1], env_list);
            close(fd[0]);
            close(fd[1]);
            exit(0);
        } else
            wait(NULL);
    }
}

int pipe_cmd(char *command, env_t **env_list)
{
    char **cmd_cut = cut_cmd(command, '|');
    int len = tab_len(cmd_cut);

    if (len == 2)
        simple_pipe(cmd_cut, env_list);
    return (IGNORE_EXIT);
}