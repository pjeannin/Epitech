/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** main
*/

#include "menger.h"

int error_handling(int argc, char **argv)
{
    int power = 1;
    if (argc != 3)
        return (1);
    for (int i = 0; argv[1][i]; ++i)
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return (1);
    for (int i = 0; argv[2][i]; ++i)
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (1);
    if (atoi(argv[2]) == 0)
        return (1);
    for (int i = 0; i < atoi(argv[2]); ++i)
        power *= 3;
    if (atoi(argv[1]) % power)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv))
        return (84);

    menger(0, 0, atoi(argv[1]), atoi(argv[2]));
    return (0);
}