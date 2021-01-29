/*
** EPITECH PROJECT, 2020
** CPE_dante_2019/generator
** File description:
** main
*/

#include "include/generator.h"

int main(int ac, char **av)
{
    int perfect = 0;

    if (error_handling(ac, av)) {
        write(2, "Invalid arguments.\n", 19);
        return (84);
    }
    if (ac == 4)
        perfect = 1;
    if (generation(atoi(av[1]), atoi(av[2]), perfect))
        return (84);
    return (0);
}