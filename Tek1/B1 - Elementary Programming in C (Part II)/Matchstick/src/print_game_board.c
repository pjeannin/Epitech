/*
** EPITECH PROJECT, 2020
** print_borad_line.c
** File description:
** matchstick
*/

#include <unistd.h>
#include <stdlib.h>
#include "matchstick.h"

void print_space(int **tab, int i, int size)
{
    for (int j = 0; j < (tab[size - 1][0] - tab[i][0]) / 2; ++j)
        put_char(' ');
}

void print_game_board(int **tab, int size)
{
    for (int i = 0; i < tab[size - 1][0] + 2; ++i)
        put_char('*');
    put_char('\n');
    for (int i = 0; i < size; ++i) {
        put_char('*');
        print_space(tab, i, size);
        for (int j = 0; j < tab[i][0] - tab[i][1]; ++j)
            put_char('|');
        for (int j = 0; j < tab[i][1]; ++j)
            put_char(' ');
        print_space(tab, i, size);
        put_str("*\n");
    }
    for (int i = 0; i < tab[size - 1][0] + 2; ++i)
        put_char('*');
    put_char('\n');
}