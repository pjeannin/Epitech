/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_malloc
*/

#include "../../include/my.h"

char **my_malloc_db(int height, int width)
{
    int e = 0;
    char **grid = malloc(sizeof(char *) * (height + 1));

    if (!grid)
        return (NULL);
    for (e = 0; e < height; e++) {
        grid[e] = malloc(sizeof(char) * (width + 1));
        if (!grid[e])
            return (NULL);
    }
    grid[e] = NULL;
    return (grid);
}

void **my_malloc_type(int height, int width, int size_db, int size)
{
    int e = 0;
    void **grid = malloc(size_db * (height + 1));

    if (!grid)
        return (NULL);
    for (e = 0; e < height; e++) {
        grid[e] = malloc(size * (width + 1));
        if (!grid[e])
            return (NULL);
    }
    grid[e] = NULL;
    return (grid);
}