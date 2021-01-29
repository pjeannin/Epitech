/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** minishell1
*/

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    int ret_val = 0;
    env_t *env_list = transform_env(envp);

    if (ac != 1) {
        put_error_str("./mysh don't need arguments\n");
        return (84);
    }
    ret_val = minishell(&env_list);
    free_list(env_list);
    return (ret_val);
}