/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** write_command
*/

#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void simple_write(char **cmd, env_t **env_list)
{
    pid_t pid = fork();
    FILE *file;
    int fd;
    int status;

    if (pid == 0) {
        file = fopen(cmd[1], "w");
        fclose(file);
        fd = open(cmd[1], O_WRONLY);
        get_command(concat_sstr("chmod +rwx ", cmd[1]), env_list);
        dup2(fd, STDOUT_FILENO);
        get_command(cmd[0], env_list);
        close(fd);
        exit(0);
    } else if (pid == -1)
        perror("fork");
    else
        wait(&status);
}

void double_write(char **cmd, env_t **env_list)
{
    return;
}

void write_command(char *command, char **cmd, env_t **env_list)
{
    int fd;
    int simple = 1;

    for (int i = 0; command[i]; ++i)
        if (command[i] == '>' && command[i + 1] == '>') {
            simple = 0;
            break;
        }
    if (simple)
        simple_write(cmd, env_list);
    else
        double_write(cmd, env_list);
}