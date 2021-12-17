/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** cdup
*/

#include "ftp.h"

void cdup(char **command, client_t *client)
{
    int ret_val = 0;

    if (tab_len(command) != 1) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    ret_val = chdir("../");
    if (ret_val == -1) {
        dprintf(client->fd, "550 Fail to change directory.\n");
        return;
    }
    dprintf(client->fd, "250 Directory Successfully changed.\n");
}