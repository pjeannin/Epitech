/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_pipes
*/

#include "error_handling.h"

int check_pipes(char **input, int start, int end)
{
    int index = find_pipe_start(input);
    
    if (index < 0)
        return (-1);
    for (; input[index]; ++index) {
        if (input[index][0] == '#')
            ++index;
        if (check_line(input[index]) < 0)
            return (-1);
    }
    return (0);
}