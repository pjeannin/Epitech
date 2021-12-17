/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** calloc
*/

#include "../include/my_malloc.h"

void *calloc(size_t nmemb , size_t size)
{
    int *tab = malloc(nmemb * size);

    if (!tab)
        return (tab);
    for (size_t i = 0; i < size; ++i)
        tab[i] = 0;

    return (tab);
}