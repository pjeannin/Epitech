/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** error_handling
*/

#include "../include/generator.h"

int error_handling(int ac, char **av)
{
    if ((ac != 3 && ac != 4) || (is_not_a_num(av[1]) || is_not_a_num(av[2])))
        return (1);
    if (ac == 4 && str_comp("perfect", av[3]))
        return (1);
    return (0);
}