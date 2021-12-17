/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** noop
*/

#include "ftp.h"

void noop(char **command, client_t *client)
{
    if (tab_len(command) != 1) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
        return;
    }
    dprintf(client->fd, "200 Command okay.\n");
}