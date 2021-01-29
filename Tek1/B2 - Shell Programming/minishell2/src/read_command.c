/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** read_command
*/

#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void simple_read(char **cmd, env_t **env_list)
{
    int fd = open(cmd[1], O_RDONLY);
    pid_t pid;
    int status;

    if (fd < 0) {
        write(2, cmd[1], str_len(cmd[1]));
        write(2, NO_FILE, str_len(NO_FILE));
        return;
    }
    pid = fork();
    if (!pid) {
        dup2(fd, STDIN_FILENO);
        get_command(cmd[0], env_list);
        close(fd);
        exit(0);
    } else
        wait(&status);
}

void double_read(char **cmd, env_t **env_list)
{
    char *input = read_stdin(cmd[1]);
    FILE *file = fopen(".test", "w");
    int fd;
    long move = 0;
    int pid;
    int status;
    char *buf;

    fclose(file);
    fd = open(".test", O_WRONLY);
    write(fd, input, str_len(input));
    close(fd);
    cmd[1] = ".test";
    simple_read(cmd, env_list);
}

void read_command(char *command, char **cmd, env_t **env_list)
{
    int simple = 1;

    for (int i = 1; command[i]; ++i)
        if (command[i] == '<' && command[i - 1] == '<')
            simple = 0;
    if (simple)
        simple_read(cmd, env_list);
    else
        double_read(cmd, env_list);
}