/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_start_infos
*/

#include "lemin.h"
#include "my.h"

void display_start_infos(char **input)
{
    int print = 0;
    my_putstr("#number_of_ants\n");
    for (int i = 0; input[i]; ++i) {
        if (i == 1)
            my_putstr("#rooms\n");
        for (int j = 0; input[i][j]; ++j)
            if (input[i][j] == '-')
                ++print;
        if (print == 1)
            my_putstr("#tunnels\n");
        my_putstr(input[i]);
        my_putstr("\n");
    }
    my_putstr("#moves\n");
}