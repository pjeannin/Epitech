/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** 102architect
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

void error_message(char *str)
{
    write(2, str, str_len(str));
    exit(84);
}

void check_is_number(char *str)
{
    int j = 0;
    int count_dot = 0;

    if (str[j] == '-')
        ++j;
    for (int i = j; str[i]; ++i) {
        if (str[i] == '.') {
            ++count_dot;
            ++i;
        }
        if ((count_dot > 1) || (str[i] < '0' || str[i] > '9'))
            error_message("Incorrect argument");
    }
}

void error_handling(int ac, char **av)
{
    int i;

    if (ac < 5)
        error_message("Too few arguments");
    for (i = 1; i <= 2; ++i)
        for (int j = 0; av[i][j]; ++j)
            check_is_number(av[i]);
    while (i < ac)
        if (av[i][0] == '-' && (av[i][1] == 't' || av[i][1] == 'z') && av[i][2] == '\0') {
            ++i;
            if (i >= ac)
                error_message("Incorrect arguments");
            check_is_number(av[i]);
            ++i;
            if (i >= ac)
                error_message("Incorrect arguments");
            check_is_number(av[i]);
            ++i;
        } else if (av[i][0] == '-' && (av[i][1] == 's' || av[i][1] == 'r') && av[i][2] == '\0') {
            ++i;
            if (i >= ac)
                error_message("Incorrect arguments");
            check_is_number(av[i]);
            ++i;
        } else {
            write(2, "Incorrect argument", 18);
            exit(84);
        }
}