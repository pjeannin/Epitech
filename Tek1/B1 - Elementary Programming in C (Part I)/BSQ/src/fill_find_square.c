/*
** EPITECH PROJECT, 2019
** fill_find_square.c
** File description:
** BSQ
*/

#include "bsq.h"
#include <stdlib.h>

int __try_square(int width, int *nbr_line, int *nbr_col, int col, int line,
                int i, char **map)
{
    for (int j = 0; j < width; ++j) {   
        if (((line + i) >= *nbr_line) || ((col + j) >= *nbr_col))
            return (1);
        if (map[line + i][col + j] == 'o' || map[line + i][col + j] == '\n'
            || map[line + i][col + j] == '\0')
            return (1);
    }
    return (0);
}

struct square *try_square(char **map, int line, int col, int lenght, int width,
                struct square *prev, int *nbr_line, int *nbr_col)
{
    int re = 0;
    int x = prev->x;
    int y = prev->y;
    int len = prev->lenght;

    for (int i = 0; i < lenght; ++i) {
        re = __try_square(width, nbr_line, nbr_col, col, line, i, map);
        if (re)
            return(prev);
    }
    set_struct_to(prev, lenght, line, col);
    prev = try_square(map, line, col, (lenght + 1), (width + 1), prev, nbr_line,
                        nbr_col);
    if (((prev->lenght) * (prev->width)) > ((len) * (len))) {
        return (prev);
    } else
        set_struct_to(prev, len, x ,y);
    return (prev);
}

void fill_square(char **map, struct square *bigger)
{
    for (int i = bigger->x; i < (bigger->x + bigger->lenght); ++i)
        for (int j = bigger->y; j < (bigger->y + bigger->width); ++j)
            map[i][j] = 'x';
}

struct square *__find_square(char **map, int *nb_col, int *nb_line,
                            struct square *bigger, int i)
{
    for (int j = 0; j < *nb_col; ++j) {
        bigger = try_square(map, i, j, bigger->width, bigger->lenght, bigger,
                            nb_line, nb_col);
        if ((bigger->width == ((*nb_col) - j))
        && (bigger->lenght == ((*nb_line) - i))) {
            bigger->find = 1;
            return (bigger);
        }
    }
    return (bigger);
}

void find_square(char **map, int *nbr_col, int *nbr_line)
{
    struct square *bigger = struct_square_init();
    for (int i = 0; i < *nbr_line; ++i) {
        bigger = __find_square(map, nbr_col, nbr_line, bigger, i);
        if (bigger->find) {
            fill_square(map, bigger);
            return;
        }
    }
    fill_square(map, bigger);
}