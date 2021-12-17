/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** pwd
*/

#include "ftp.h"

void pwd(char **command, client_t *client)
{
    char *path;

    if (tab_len(command) != 1) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    path = malloc(sizeof(char) * 200);
    path = getcwd(path, 200);
    dprintf(client->fd, "257 %s\n", path);
    free(path);
}