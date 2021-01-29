/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** matchstick
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "matchstick.h"

int main(int ac, char **av)
{
    int size;
    int max_matches;
    int **tab;
    int ret = 0;

    srand(time(NULL));
    if (error_handling(av[1], av[2], ac)) {
        write(2, "Incorrect size or max matche(s)", 31);
        return (84);
    }
    size = my_getnbr(av[1]);
    max_matches = my_getnbr(av[2]);
    tab = creat_tab(size);
    print_game_board(tab, size);
    ret = matchstick(tab, size, max_matches);
    free_tab(tab, size);
    return (ret);
}