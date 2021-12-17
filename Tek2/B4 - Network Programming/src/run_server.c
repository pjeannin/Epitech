/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** run_server
*/

#include "ftp.h"

static void handle_commands(client_t **clients, fd_set *rdfs, server_t *server)
{
    char *line;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (clients[i] && FD_ISSET(clients[i]->fd, rdfs)) {
            line = get_line(clients[i]->fd);
            if (line) {
                interpret_command(split_string(line, " \t\n\r"), clients[i]);
            }
            free(line);
        }
    }
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (clients[i] && clients[i]->quit) {
            close(clients[i]->fd);
            free(clients[i]);
            clients[i] = NULL;
        }
    }
}

static int get_max_fd(server_t *server, client_t **clients)
{
    int max = server->server_fd;

    for (int i = 0; i < MAX_CLIENT; ++i)
        if (clients[i]) {
            if (clients[i]->fd > max)
                max = clients[i]->fd;
        }

    return (max);
}

static void set_rdfs(fd_set *rdfs, server_t *server, client_t **clients)
{
    FD_ZERO(rdfs);
        FD_SET(server->server_fd, rdfs);
        for (int i = 0; i < MAX_CLIENT; ++i) {
            if (clients[i])
                FD_SET(clients[i]->fd, rdfs);
        }
}

int run_server(server_t *server)
{
    struct sockaddr_in client;
    client_t **clients = create_empty_client_tab();
    fd_set rdfs;

    while (1) {
        set_rdfs(&rdfs, server, clients);
        select(get_max_fd(server, clients) + 1, &rdfs, NULL, NULL, NULL);
        if (FD_ISSET(server->server_fd, &rdfs)) {
            server->client_fd = accept(server->server_fd,
            (struct sockaddr *)&client, &server->sock_size);
            accepted_client(server, inet_ntoa(client.sin_addr), clients);
        }
        handle_commands(clients, &rdfs, server);
    }

    return (RETURN_SUCCESS);
}