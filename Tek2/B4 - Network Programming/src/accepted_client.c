/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** accepted_client
*/

#include "ftp.h"

static int find_empty_client(client_t **clients)
{
    for (int i = 0; i < MAX_CLIENT; ++i)
        if (clients[i] == 0)
            return (i);

    return (-1);
}

void accepted_client(server_t *server, char *ip_adress, client_t **clients)
{
    client_t *client = new_client(server, ip_adress);
    char *line;

    if (client == (client_t *)RETURN_FAILURE)
        return;
    if (find_empty_client(clients) == -1)
        return;
    clients[find_empty_client(clients)] = client;
    dprintf(server->client_fd, "220 You are connected.\n");

    return;
}