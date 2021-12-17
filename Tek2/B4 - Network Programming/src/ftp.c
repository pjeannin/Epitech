/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** ftp
*/

#include "ftp.h"

int ftp(int port, char *starting_directory)
{
    server_t server;
    struct sockaddr_in client;

    if (init_ftp_server(&server, port, starting_directory) == -1)
        return (RETURN_FAILURE);
    if (run_server(&server))
        return (RETURN_FAILURE);
    close(server.server_fd);

    return (RETURN_SUCCESS);
}