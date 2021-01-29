/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_ennemy
*/

#include "my_defender.h"

int add_ennemy(defender_t *defender)
{
    static int call = 100;
    int verif;

    while (defender->ennemy_list->next)
        defender->ennemy_list = defender->ennemy_list->next;
    if (call % 100 == 0) {
        for (int i = 0; i < defender->level; ++i) {
            if (defender->ennemy_list->ennemy) {
                if ((defender->ennemy_list->next = create_empty_ennemy_list()) == NULL)
                    return (1);
                defender->ennemy_list->next->prev = defender->ennemy_list;
                defender->ennemy_list = defender->ennemy_list->next;
            }
            if ((defender->ennemy_list->ennemy = 
            create_ennemy(100, 1, defender, 2)) == NULL)
                return (1);
        }
    }
    ++call;
    return (0);
}