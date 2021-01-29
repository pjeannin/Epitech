/*
** EPITECH PROJECT, 2020
** player.c
** File description:
** matchtick
*/

#include "matchstick.h"

int check_error_player(int **tab, int line, int matches, int *ok, int max_match)
{
    *ok = 1;
    if (tab[line - 1][0] - tab[line - 1][1] < matches) {
        *ok = 0;
        put_str("Error: not enough matches on this line\n");
    } else if (matches == 0) {
        *ok = 0;
        put_str("Error: you have to remove at least one match\n");
    } else if (matches > max_match) {
        *ok = 0;
        put_str("Error: you cannot remove more than ");
        put_nbr(max_match);
        put_str(" matches per turn\n");
    }
    return (0);
}

int **player(int **tab, int size, int max_matchs)
{
    int line;
    int matches;
    int go = 0;
    int ok = 0;

    while (ok == 0) {
        while (go == 0)
            line = get_line(tab, size, &go);
        if (line == -1)
            return ((int **)-1);
        go = 0;
        while (go == 0)
            matches = get_matches(tab, line, &go);
        if (matches == -1)
            return ((int **)-1);
        go = check_error_player(tab, line, matches, &ok, max_matchs);
    }
    disp(line, matches, 'p');
    update_game_board(line, matches, tab, size);
    return (tab);
}