/*
** EPITECH PROJECT, 2020
** ai.c
** File description:
** matchstick
*/

#include "matchstick.h"

int way_one(int **tab, int size, int max_matches, int *matches)
{
    int line = 0;

    for (int i = 0; i < size; ++i)
        if ((tab[i][0] - tab[i][1]) > max_matches / 2) {
            line = i + 1;
            *matches = max_matches / 2 + 1;
            return (line);
        }
    return (-1);
}

int way_two(int **tab, int size, int max_matches, int *matches)
{
    int line;

    for (int i = 0; i < size; ++i)
        if (tab[i][0] - tab[i][1] <= max_matches
        && tab[i][0] - tab[i][1] > 1) {
            line = i + 1;
            *matches = tab[i][0] - tab[i][1] - 1;
            return (line);
        }
    return (-1);
}

int way_three(int **tab, int size, int max_matches, int *matches)
{
    int line;

    for (int i = 0; i < size; ++i)
        if (tab[i][0] - tab[i][1] > 0) {
            line = i + 1;
            *matches = 1;
            return (line);
        }
    return (-1);
}

int **ai(int **tab, int size, int max_matches)
{
    int line = -1;
    int matches = 0;

    line = way_one(tab, size, max_matches, &matches);
    if (line == -1)
        line = way_two(tab, size, max_matches, &matches);
    if (line == -1)
        line = way_three(tab, size, max_matches, &matches);
    disp(line, matches, 'a');
    update_game_board(line, matches, tab, size);
    return (tab);
}