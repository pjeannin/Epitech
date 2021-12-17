/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** interpret_commands
*/

#include "ftp.h"

void interpret_command(char **command, client_t *client)
{
    const char *function_names[14] = { "USER", "PASS", "CWD", "CDUP", "QUIT", \
                                        "DELE", "PWD", "PASV", "PORT", "HELP", \
                                        "NOOP", "RETR", "STOR", "LIST" };
    void (*function[14])(char **tab, client_t *c) = { &user, &pass, &cwd, \
                                        &cdup, &quit, &dele, &pwd, &pasv, \
                                        &port, &help, &noop, &retr, &stor, \
                                        &list };

    if (!command) {
        dprintf(client->fd, "500 Unknown command.\n");
        return;
    }
    for (int i = 0; i < 14; ++i)
        if (!strcmp(command[0], function_names[i])) {
            function[i](command, client);
            break;
        } else if (i == 13) {
            dprintf(client->fd, "500 Unkownn command.\n");
        }
    free_tab(command);
}