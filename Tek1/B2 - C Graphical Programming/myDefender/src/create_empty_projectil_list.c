/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_empty_projectil_list
*/

#include "my_defender.h"

projetcil_list_t *create_empty_projectil_list(void)
{
    projetcil_list_t *return_val = malloc(sizeof(projetcil_list_t));

    if (return_val == NULL)
        return (NULL);
    return_val->next = NULL;
    return_val->prev = NULL;
    return_val->projectil = NULL;
    return (return_val);
}