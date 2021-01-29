/*
** EPITECH PROJECT, 2020
** exe_command.c
** File description:
** minshell 1
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"

void catchs(int sig)
{
    put_str("Segmentation fault\n");
    put_str(PROMPT);
}

void exec(char **new_argv, char **new_env, int *ok)
{
    if (execve(new_argv[0], new_argv, new_env) != -1)
        ++(*ok);
}

void son(char *command, env_t **env_list, int *ok, char **cmd)
{
    char **tab = creat_tab(env_list);
    char **new_argv = create_word_list(command, env_list);
    char **new_env = list_to_tab(*env_list);

    signal(SIGSEGV, catchs);
    *cmd = new_argv[0];
    if ((*cmd)[0] == '.' && (*cmd)[1] == '/') {
        *cmd = &((*cmd)[2]);
        new_argv[0] = concat_str(find_val(env_list, "PWD"), *cmd);
        exec(new_argv, new_env, ok);
    } else {
        for (int i = 0; tab[i]; ++i) {
            new_argv[0] = concat_str(tab[i], *cmd);
            exec(new_argv, new_env, ok);
        }
    }
    free_tab(new_env);
    free_tab(new_argv);
}

void exe_command(char *command, env_t **env_list)
{
    char *cmd;
    int ok = 0;
    int status;
    pid_t PID = fork();

    if (PID == 0) {
        son(command, env_list, &ok, &cmd);
        if (ok == 0) {
            put_error_str(cmd);
            put_error_str(": Command not found.\n");
            exit(0);
        } else
            kill(PID, SIGTERM);
    } else if (PID == -1)
        perror("fork");
    else
        wait(&status);
}