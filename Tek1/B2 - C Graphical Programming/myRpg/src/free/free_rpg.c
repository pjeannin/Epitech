/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_rpg
*/

#include "my_rpg.h"

void my_free(char *str)
{
    if (str)
        free(str);
}

void free_rpg(game_t *game_struct)
{
    if (game_struct)
        free(game_struct);
    if (tabpar)
        free(tabpar);
    if (but)
        free(but);
    if (tabinvent)
        free(tabinvent);
    if (tabgame)
        free(tabgame);
}