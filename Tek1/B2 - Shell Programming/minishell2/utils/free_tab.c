/*
** EPITECH PROJECT, 2020
** free_tab.c
** File description:
** minishell1
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
}