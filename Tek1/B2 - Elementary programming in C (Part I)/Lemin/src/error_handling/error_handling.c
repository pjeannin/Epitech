/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** error_handling
*/

#include "error_handling.h"
#include "get_input.h"

char **error_handling(int ac, char **av)
{
    char **input;

    if (ac != 1)
        return (NULL);
    input = input_is_wrong();
    return (input);
}