/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "include/solver.h"

int main(int ac, char **av)
{
    maze_t *maze_struct = get_maze(av[1]);

    if (maze_struct < (maze_t *)0)
        return (84);
    maze_struct = solve(maze_struct);
    for (int i = 0; i < maze_struct->nb_line; ++i)
        for (int j = 0; j < maze_struct->nb_col; ++j)
            if (maze_struct->maze[i][j] == 'O')
                maze_struct->maze[i][j] = 'o';
    for (int i = 0; i < maze_struct->nb_line; ++i)
        printf("%s", maze_struct->maze[i]);
    return (0);
}