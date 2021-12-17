/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** pass
*/

#include "ftp.h"

void pass(char **command, client_t *client)
{
    char *password = command[1] ? command[1] : "";

    if (tab_len(command) > 2 || client->is_logged_in != ONLYUSERNAME) {
        if (tab_len(command) > 2)
            dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
        else
            dprintf(client->fd, "332 Need account for login.\n");
        return;
    }
    if (!strcmp(password, "") && !strcmp(client->username, "Anonymous")) {
        client->password = strdup(password);
        client->is_logged_in = LOGGEDIN;
        dprintf(client->fd, "230 User logged in, proceed.\n");
    } else {
        dprintf(client->fd, "530 Invalid username or password\n");
    }
}