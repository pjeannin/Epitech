/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** $
*/

#include "ftp.h"

void display_error(client_t *client, char *error)
{
    dprintf(client->fd, "%s", error);
}