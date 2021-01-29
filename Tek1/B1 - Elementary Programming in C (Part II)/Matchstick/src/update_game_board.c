/*
** EPITECH PROJECT, 2020
** update_game_board.c
** File description:
** matchstick
*/

#include <unistd.h>
#include "matchstick.h"

int **update_game_board(int line, int nb_matches, int **tab, int size)
{
    if (line > size || line < 0) {
        write(2, "Incorrect line\n", 15);
        return (tab);
    }
    if (nb_matches > (tab[line - 1][0]) - tab[line  - 1][1]) {
        write(2, "Incorrect matches\n", 18);
        return (tab);
    }
    tab[line - 1][1] += nb_matches;
    return (tab);
}