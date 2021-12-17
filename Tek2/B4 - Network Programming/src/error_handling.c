/*
** EPITECH PROJECT, 2021
** B4 - Network Programming
** File description:
** error_handling
*/

#include "ftp.h"

int error_handling(int argc, char **argv)
{
    DIR *starting_directory;

    if (argc != 3)
        return (RETURN_FAILURE);
    for (int i = 0; argv[1][i]; ++i)
        if (!isdigit(argv[1][i]))
            return (RETURN_FAILURE);
    starting_directory = opendir(argv[2]);
    if (!starting_directory)
        return (RETURN_FAILURE);
    closedir(starting_directory);

    return (RETURN_SUCCESS);
}