/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** new_client
*/

#include "ftp.h"

client_t *new_client(server_t *server, char *ip_adress)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return ((client_t *)RETURN_FAILURE);
    client->fd = server->client_fd;
    client->ip = ip_adress;
    client->username = NULL;
    client->password = NULL;
    client->is_logged_in = LOGGEDOUT;
    client->quit = 0;
    client->port_pasv_fd = -1;
    client->pasv_port = -1;
    client->port_pasv_mode = STATUS_NO;

    return (client);
}