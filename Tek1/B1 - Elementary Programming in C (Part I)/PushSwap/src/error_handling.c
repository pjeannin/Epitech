/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** pushswap
*/

#include <unistd.h>

int check_is_number(char *str)
{
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-') {
        write(2, "Incorrect arguments", 19);
        return (1);
    }
    for (int i = 1; str[i]; ++i)
        if (str[i] < '0' || str[i] > '9') {
            write(2, "Incorrect arguments", 19);
            return (1);
        }
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac == 1) {
        write(2, "Need arguments", 19);
        return (1);
    }
    for (int i = 1; i < ac; ++i)
        if (check_is_number(av[i]))
            return (1);
    return (0);
}