/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** find_initial_ennemy_pos
*/

#include "my_defender.h"

sfVector2f find_initial_ennemy_pos(defender_t *defender, int y_pos)
{
    sfVector2f ennemy_pos;
    int min;
    int max;

    srand(time(NULL));
    for (int i = 0; i < 15; ++i)
        if (defender->map1_construction[0][i] == 1 
        && defender->map1_construction[0][i + 1] == 3)
            min = i * 120;
        else if (defender->map1_construction[0][i] == 3
        && defender->map1_construction[0][i + 1] == 1)
            max = i * 120;
    ennemy_pos.x = rand() % (max - min) + min;
    ennemy_pos.y = - y_pos * 50;
    return (ennemy_pos);
}