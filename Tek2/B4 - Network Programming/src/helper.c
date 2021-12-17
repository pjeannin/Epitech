/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** helper
*/

#include "ftp.h"

int helper(int argc, char **argv)
{
    if (argc == 2 && !strcmp("-help", argv[1])) {
        printf("USAGE: ./myftp port path\n\tport is the port number on which \
the server socket listens\n\tpath is the path to the home directory \
for the Anonymous user");
        return (RETURN_SUCCESS);
    }

    return (RETURN_FAILURE);
}