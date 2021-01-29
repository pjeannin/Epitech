/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_ennemy_list
*/

#include "my_defender.h"

ennemy_list_t *init_ennemy_list(int level, defender_t *defender)
{
    ennemy_list_t *ennemy_list = malloc(sizeof(ennemy_list_t));

    if (ennemy_list == NULL)
        return (NULL);
    ennemy_list->next = NULL;
    ennemy_list->prev = NULL;
    if ((ennemy_list->ennemy = create_ennemy(100, 1, defender, -1)) == NULL)
        return (NULL);
    for (int i = 0; i < level; ++i) {
        if ((ennemy_list->next = malloc(sizeof(ennemy_list_t))) == NULL)
            return (NULL);
        ennemy_list->next->prev = ennemy_list;
        ennemy_list->next->next = NULL;
        ennemy_list = ennemy_list->next;
        if ((ennemy_list->ennemy = create_ennemy(100, 1, defender, 3 * i)) == NULL)
            return (NULL);
        ennemy_list->next = NULL;
    }
    return (ennemy_list);
}