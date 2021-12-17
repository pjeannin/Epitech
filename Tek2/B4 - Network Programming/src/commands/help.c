/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** help
*/

#include "ftp.h"

static void display_command_description(char **command, client_t *client,
const char **function_names, const char **description)
{
    for (int i = 0; i < 14; ++i) {
        if (!strcmp(command[1], function_names[i])) {
            dprintf(client->fd, "214 %s:%s\n", function_names[i],
            description[i]);
            return;
        }
    }
    dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
}

void help(char **command, client_t *client)
{
    const char *function_names[14] = { "USER", "PASS", "CWD", "CDUP", "QUIT", \
                                        "DELE", "PWD", "PASV", "PORT", "HELP", \
                                        "NOOP", "RETR", "STOR", "LIST" };
    const char *description[14] = { USER, PASS, CWD, CDUP, QUIT, \
                                        DELE, PWD, PASV, PORT, HELP, \
                                        NOOP, RETR, STOR, LIST };

    if (tab_len(command) == 1) {
        dprintf(client->fd, "214 Available commands : ");
        for (int i = 0; i < 13; ++i)
            dprintf(client->fd, "%s, ", function_names[i]);
        dprintf(client->fd, "%s\n", function_names[13]);
        return;
    } else if (tab_len(command) != 2) {
        dprintf(client->fd, "504 Command not implemented for that \
parameter.\n");
        return;
    }
    display_command_description(command, client, function_names, description);
}