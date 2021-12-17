/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** stor
*/

#include "ftp.h"

static void receive_file(char *filepath, int fd, client_t *client)
{
    int file = open(filepath,O_CREAT | O_WRONLY | O_TRUNC, 0666);
    char tmp[2048];
    ssize_t size;

    if (file == -1) {
        dprintf(client->fd, "550 an error occured./n");
        return;
    }
    dprintf(client->fd, "150 File open, start transfer.\n");
    while ((size = read(fd, tmp, 204)) > 0) {
        tmp[size] = '\0';
        dprintf(file, "%s", tmp);
    }
    close(file);
    close(client->port_pasv_fd);
    close(fd);
    client->port_pasv_fd = -1;
    dprintf(client->fd, "226 Transfer OK.\n");
}

void stor(char **command, client_t *client)
{
    int fd;

    if (tab_len(command) != 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
    return;
    } else if (client->is_logged_in != LOGGEDIN) {
        dprintf(client->fd, "530 Not logged in.");
        return;
    }
    if (fork() == 0) {
        fd = init_data_transfer_connection(client);
        if (fd == -1)
            exit(0);
        receive_file(command[1], fd, client);
        exit(0);
    }
}