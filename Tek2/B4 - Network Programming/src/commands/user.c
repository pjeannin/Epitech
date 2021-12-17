/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** user
*/

#include "ftp.h"

void user(char **command, client_t *client)
{
    if (tab_len(command) != 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
        return;
    }
    client->is_logged_in = ONLYUSERNAME;
    free(client->username);
    client->username = strdup(command[1]);
    dprintf(client->fd, "331 User name okay, need password.\n");
}