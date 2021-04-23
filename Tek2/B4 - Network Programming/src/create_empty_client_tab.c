/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** create_empty_client_tab
*/

#include "ftp.h"

client_t **create_empty_client_tab(void)
{
    client_t **tab = malloc(sizeof(client_t) * MAX_CLIENT);

    if (!tab)
        return ((client_t **)RETURN_FAILURE);
    for (int i = 0; i < MAX_CLIENT; ++i)
        tab[i] = NULL;

    return tab;
}