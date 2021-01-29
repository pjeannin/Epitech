/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_end_start
*/

#include "error_handling.h"
#include "my.h"

int check_start_end(char **input, int *start, int *end)
{
    int index = find_cmd(input, "##start");

    if (index < 0)
        return (- 1);
    for (int i = 0; input[index][i]; ++i)
        if (input[index][i] < '0' || input[index][i] > '9')
            if (input[index][i] != ' ')
                return (- 1);
    *start = my_getnbr(input[index]);
    index = find_cmd(input, "##end");
    if (index < 0)
        return (- 1);
    for (int i = 0; input[index][i]; ++i)
        if (input[index][i] < '0' || input[index][i] > '9')
            if (input[index][i] != ' ')
                return (- 1);
    *end = my_getnbr(input[index]);
    return (0);
}