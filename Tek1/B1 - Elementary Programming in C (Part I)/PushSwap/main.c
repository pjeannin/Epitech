/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** pushswap
*/

#include "pushswap.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av))
        return (84);
    if (ac == 2) {
        write(1, "\n", 1);
        return (0);
    }
    linked_list_t *list = arg_in_linkedlist((ac - 1), av);
    list = sort(list);
    free_linked_list(list);
}
