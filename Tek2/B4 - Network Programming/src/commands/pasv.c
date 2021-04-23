/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** pasv
*/

#include "ftp.h"

static void set_sock_in(struct sockaddr_in *sock_in)
{
    sock_in->sin_port = htons(0);
    sock_in->sin_family = AF_INET;
    sock_in->sin_addr.s_addr = htonl(INADDR_ANY);
}

static void display(client_t *client)
{
    char **ip_tab = split_string(strdup(client->ip), ".");

    dprintf(client->fd, "227 Entering Passiv mode (");
    for (int i = 0; ip_tab[i]; ++i)
        dprintf(client->fd, "%s,", ip_tab[i]);
    dprintf(client->fd, "%d,%d).\n", client->pasv_port / 256, \
    client->pasv_port % 256);
}

static void enter_pasv(client_t *client)
{
    struct sockaddr_in sock_in;
    socklen_t size = sizeof(sock_in);

    if (!(client->port_pasv_fd != -1))
        close(client->port_pasv_fd);
    client->port_pasv_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (client->port_pasv_fd == -1)
        return (display_error(client, "500 Cannot enter passiv mode.\n"));
    set_sock_in(&sock_in);
    if (bind(client->port_pasv_fd, (struct sockaddr *)&sock_in, \
    sizeof(sock_in)) == -1)
        return (display_error(client, "500 Cannot enter passiv mode.\n"));
    if (listen(client->port_pasv_fd, 1) == -1)
        return (display_error(client, "500 Cannot enter passiv mode.\n"));
    if (getsockname(client->port_pasv_fd, (struct sockaddr *)&sock_in, \
    &size) == -1)
        return (display_error(client, "500 Cannot enter passiv mode.\n"));
    client->pasv_port = ntohs(sock_in.sin_port);
    client->port_pasv_mode = STATUS_PASV;
    display(client);
}

void pasv(char **command, client_t *client)
{
    if (tab_len(command) != 1) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    enter_pasv(client);
}