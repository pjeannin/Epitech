/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** port
*/

#include "ftp.h"

static int str_composed_of_int(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (!isdigit(str[i]))
            return (RETURN_FAILURE);

    return (RETURN_SUCCESS);
}

static int command_is_invalid(char **tab)
{
    if (tab_len(tab) != 6)
        return (RETURN_FAILURE);
    for (int i = 0; tab[i]; ++i)
        if (str_composed_of_int(tab[i]) == RETURN_FAILURE)
            return (RETURN_FAILURE);

    return (RETURN_SUCCESS);
}

static void enter_port(client_t *client, char **arg)
{
    struct sockaddr_in sock_in;
    socklen_t size = sizeof(sock_in);
    if (command_is_invalid(arg) == RETURN_FAILURE)
        return (display_error(client, "500 Cannot run PORT command.\n"));
    if (client->port_pasv_fd != -1)
        return (display_error(client, "500 Cannot run PORT command.\n"));
    client->port_pasv_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (client->port_pasv_fd == -1)
        return (display_error(client, "500 Cannot run PORT command.\n"));
    sock_in.sin_port = htons(atoi(arg[4]) * 256 + atoi(arg[5]));
    sock_in.sin_family = AF_INET;
    sock_in.sin_addr.s_addr = inet_addr(get_ip_from_tab(arg));
    if (connect(client->port_pasv_fd, (struct sockaddr *)&sock_in, size) == -1)
        return (display_error(client, "500 Cannot run PORT command.\n"));
    client->port_pasv_mode = STATUS_PORT;
    dprintf(client->fd, "200 PORT command succed.\n");
}

void port(char **command, client_t *client)
{
    if (tab_len(command) != 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    enter_port(client, split_string(command[1], ",\n"));
}