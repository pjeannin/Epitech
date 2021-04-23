/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** init_data_transfer_connection
*/

#include "ftp.h"

int init_data_transfer_connection(client_t *client)
{
    struct sockaddr_in sock_in;
    socklen_t size = sizeof(sock_in);
    int fd = client->port_pasv_mode == STATUS_PORT ? client->port_pasv_fd :
    accept(client->port_pasv_fd, (struct sockaddr *)&sock_in, &size);

    if (fd == -1) {
        dprintf(client->fd, "425 connection error.\n");
        return (-1);
    }

    return (fd);
}