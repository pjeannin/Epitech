/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for the program
*/

#include "includes.h"

int main(int ac, char **av)
{
    if (ac == 2 && my_strcomp(av[1], "-h"))
        return (my_putstr(1, HELP));
    return (0);
}
