/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_empty_defense_list
*/

#include "my_defender.h"

defense_list_t *create_empty_defense_list(void)
{
    defense_list_t *defense_list = malloc(sizeof(defense_list_t));

    if (defense_list == NULL)
        return (NULL);
    defense_list->defnse = NULL;
    defense_list->next = NULL;
    defense_list->prev = NULL;
    return (defense_list);
}