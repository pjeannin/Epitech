/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"

int matchstick(int **tab, int size, int max_matches)
{
    while (1) {
        if ((tab = player(tab, size, max_matches)) == (int **)-1)
            return (84);
        print_game_board(tab, size);
        if (check_end(tab, size)) {
            put_str("You lost, too bad...\n");
            return (2);
        }
        tab = ai(tab, size, max_matches);
        print_game_board(tab, size);
        if (check_end(tab, size)) {
            put_str("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}