/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** main
*/

#include "ftp.h"

int main(int argc, char **argv)
{
    if (!helper(argc, argv))
        return (SUCCESS);
    else if (error_handling(argc, argv)) {
        fprintf(stderr, "Please verify your input. Run ./ftp -h for USAGE.\n");
        return (FAILURE);
    }
    if (ftp(atoi(argv[1]), argv[2])) {
        fprintf(stderr, "Oops something went wrong. Try again.");
        return (FAILURE);
    }

    return (SUCCESS);
}