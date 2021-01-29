/*
** EPITECH PROJECT, 2020
** check_flags.c
** File description:
** check_flags
*/

#include "my_ls.h"

void check_flags_bis_bis_bis(file_t *list, int ac, char **av)
{
    if (((av[1][0] == '-' && av[1][1] == 'F' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'l' && av[2][2] == '\0')
    || (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'a' && av[2][2] == '\0')) && (ac == 3
    || (ac == 4 && av[3][0] != '-')))
        display_lF(list);
}

void check_flags_bis_bis(file_t *list, int ac, char **av)
{
    if (((av[1][0] == '-' && av[1][1] == 'a' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'l' && av[2][2] == '\0')
    || (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'a' && av[2][2] == '\0'))
    && (ac == 3 || (ac == 4 && av[3][0] != '-')))
        display_la(list);
    else if (((av[1][0] == '-' && av[1][1] == 'l'
    && av[1][2] == '\0' && av[2][0] == '-' && av[2][1] == 'a'
    && av[2][2] == '\0') || (av[1][0] == '-' && av[1][1] == 'l'
    && av[1][2] == '\0' && av[2][0] == '-' && av[2][1] == 'a'
    && av[2][2] == '\0')) && (ac == 3 || (ac == 4 && av[3][0] != '-')))
        display_la(list);
    else if (((av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'F' && av[2][2] == '\0')
    || (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0'
    && av[2][0] == '-' && av[2][1] == 'a' && av[2][2] == '\0'))
    && (ac == 3 || (ac == 4 && av[3][0] != '-')))
        display_lF(list);
    else
        check_flags_bis_bis_bis(list, ac, av);
}

void check_flags_bis(file_t *list, int ac, char **av)
{
    if ((av[1][0] == '-' && av[1][1] == 'd' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-')))
        display_d(list);
    else if ((av[1][0] == '-' && av[1][1] == 'r' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-')))
        display_r(list);
    else if ((av[1][0] == '-' && av[1][1] == 'F' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-')))
        display_F(list);
    else
        check_flags_bis_bis(list, ac, av);
}

void c_flags(file_t *list, int ac, char **av)
{
    if ((av[1][0] == '-' && av[1][1] == 'u' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-'))) {
        list = sort_a_time(list);
        display_ls(list);
    } else if ((av[1][0] == '-' && av[1][1] == 't' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-'))) {
        display_lst(list);
    } else
        check_flags_bis(list, ac, av);
}

void check_flags(file_t *list, int ac, char **av)
{
    if (ac == 1 || (ac == 2 && av[1][0] != '-'))
        display_ls(list);
    else if ((av[1][0] == '-' && av[1][1] == 'a' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-')))
        display_lsa(list);
    else if ((av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0')
    && (ac == 2 || (ac == 3 && av[2][0] != '-')))
        display_l(list);
    else
        c_flags(list, ac, av);
}