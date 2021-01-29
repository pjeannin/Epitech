/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_defense_list
*/

#include "my_defender.h"

defense_list_t *init_defense_list(void)
{
    defense_list_t *defense_list = malloc(sizeof(defense_list_t));

    if (defense_list == NULL)
        return (NULL);
    defense_list->prev = NULL;
    if ((defense_list->defnse = create_defense(1, 4, 4)) == NULL)
        return (NULL);
    if ((defense_list->next = malloc(sizeof(defense_list_t))) == NULL)
        return (NULL);
    defense_list->next->prev = defense_list;
    defense_list = defense_list->next;
    if ((defense_list->defnse = create_defense(2, 9, 4)) == NULL)
        return (NULL);
    if ((defense_list->next = malloc(sizeof(defense_list_t))) == NULL)
        return (NULL);
    defense_list->next->prev = defense_list;
    defense_list = defense_list->next;
    if ((defense_list->defnse = create_defense(1, 4, 5)) == NULL)
        return (NULL);
    if ((defense_list->next = malloc(sizeof(defense_list_t))) == NULL)
        return (NULL);
    defense_list->next->prev = defense_list;
    defense_list = defense_list->next;
    defense_list->next = NULL;
    return (defense_list);
}