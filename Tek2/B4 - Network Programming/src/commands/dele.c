/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** dele
*/

#include "ftp.h"

void dele(char **command, client_t *client)
{
    if (tab_len(command) != 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    if (remove(command[1]) == 0)
        dprintf(client->fd, "250 File deleted.\n");
    else
        dprintf(client->fd, "550 Cannot delete the file.\n");
}