/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "my_ls.h"

int check_error(int ac, char **tab, char **dirname)
{
    if (ac > 1 && tab[ac - 1][0] != '-') {
        *dirname = tab[ac - 1];
        --ac;
    }
    else
        *dirname = ".";
    for (int i = 1; i < ac; ++i) {
        if (str_len(tab[i]) != 2)
            return (1);
        if (tab[i][1] != 'l' && tab[i][1] != 'a' && tab[i][1] != 'F'
        && tab[i][1] != 'd' && tab[i][1] != 'R' && tab[i][1] != 't' && tab[i][1] != 'u') {
            write(2, "./my_ls: illegal option -- ", 27);
            write(1, &tab[i][1], 1);
            write(2, "\nusage: ./my_ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%%] [file ...]", 70);
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    char *dirname;

    if (check_error(ac, av, &dirname))
        return (84);
    my_ls(ac, av, dirname);
    return (0);
}
