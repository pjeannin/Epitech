/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** quit
*/

#include "ftp.h"

void quit(char **command, client_t *client)
{
    if (tab_len(command) != 1) {
        dprintf(client->fd, "500 Unkown command.\n");
    } else {
        dprintf(client->fd, "221 Service closing control connection.\n");
        client->quit = 1;
    }
}