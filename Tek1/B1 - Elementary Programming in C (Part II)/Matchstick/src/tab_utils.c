/*
** EPITECH PROJECT, 2020
** tab_utils.c
** File description:
** matchstick
*/

#include <stdlib.h>
#include "matchstick.h"

int **creat_tab(int size)
{
    int line = 1;
    int **tab = malloc(sizeof(int *) * size);

    for (int i = 0; i < size; ++i) {
        tab[i] = malloc(sizeof(int) * 2);
        tab[i][0] = line;
        tab[i][1] = 0;
        line += 2;
        }
    return (tab);
}

void free_tab(int **tab, int size)
{
    for (int i = 0; i < size; ++i)
        free(tab[i]);
    free(tab);
}