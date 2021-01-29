/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** find_x_and_y_move_ennemy
*/

#include "my_defender.h"

int find_y(defender_t *defender, ennemy_t *ennemy, sfVector2f ennemy_postition)
{
    if ((int)ennemy_postition.y + 1 >= 9)
        return (0);
    switch (defender->current_mapconstruction[(int)ennemy_postition.y + 1]
    [(int)ennemy_postition.x]) {
        case 0:
            return (1);
            break;
        case 3:
            return (2);
            break;
        default:
            break;
    }
    return (0);
}

int find_x(defender_t *defender, ennemy_t *ennemy, sfVector2f ennemy_postition)
{
    if ((int)ennemy_postition.x + 1 >= 16)
        return (0);
    switch (defender->current_mapconstruction[(int)ennemy_postition.y]
    [(int)ennemy_postition.x + 1]) {
        case 0:
            return (1);
            break;
        case 3:
            return (2);
            break;
        default:
            break;
    }
    return (0);
}

