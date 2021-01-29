/*
** EPITECH PROJECT, 2020
** solver
** File description:
** main
*/

#include "bonus_solver.h"

int main(int ac, char **av)
{
    maze_t *maze_struct = get_maze(av[1]);

    if (maze_struct < (maze_t *)0)
        return (84);
    solve(maze_struct);
    return (0);
}