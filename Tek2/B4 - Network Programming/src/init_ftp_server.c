/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** init_ftp_server
*/

#include "ftp.h"

int set_data(server_t *server, int port, char *statring_directory)
{
    server->port = port;
    server->path = statring_directory;
    server->server_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (server->server_fd == -1)
        return (RETURN_FAILURE);
    server->sock_in.sin_port = htons(server->port);
    server->sock_in.sin_family = AF_INET;
    server->sock_in.sin_addr.s_addr = htonl(INADDR_ANY);
    server->sock_size = sizeof(server->sock_in);

    return (RETURN_SUCCESS);
}

int init_ftp_server(server_t *server, int port, char *statring_directory)
{
    if (chdir(statring_directory) == -1) {
        fprintf(stderr, "Can't go to %s.", statring_directory);
        return (RETURN_FAILURE);
    }
    if (set_data(server, port, statring_directory))
        return (RETURN_FAILURE);
    if (bind(server->server_fd, (struct sockaddr *)&server->sock_in,
    server->sock_size) == -1) {
        close(server->server_fd);
        return (RETURN_FAILURE);
    }
    if (listen(server->server_fd, 42) == -1) {
        close(server->server_fd);
        return (RETURN_FAILURE);
    }
    server->client_fd = -1;

    return (RETURN_SUCCESS);
}