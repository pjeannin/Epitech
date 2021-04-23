/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** list
*/

#include "ftp.h"

static void send_list(client_t *client, char *to_open)
{
    FILE *file;
    int fd = init_data_transfer_connection(client);
    char tmp[2048];

    if (fd == -1)
        return;
    file = popen(to_open, "r");
    if (file == NULL || file == (FILE *)-1) {
        dprintf(client->fd, "550 an error occured.\n");
        return;
    }
    while (fgets(tmp, 2048, file))
        dprintf(fd, "%s", tmp);
    fclose(file);
    close(client->port_pasv_fd);
    close(fd);
    client->port_pasv_fd = -1;
    dprintf(client->fd, "226 List OK.\n");
}

void list(char **command, client_t *client)
{
    if (tab_len(command) > 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    if (fork() == 0) {
        send_list(client, tab_len(command) == 2 ?
        strcat("ls -l ", command[1]) : "ls -l");
        exit(0);
    }
}