/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_first_line
*/

#include "my.h"

int check_first_line(char **input)
{
    for (int i = 0; input[0][i]; ++i)
        if (input[0][i] < '0' || input[0][i] > '9')
            return (0);
    if (my_getnbr(input[0]) == 0)
        return (0);
    return (1);
}