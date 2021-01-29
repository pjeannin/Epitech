/*
** EPITECH PROJECT, 2020
** solver
** File description:
** free
*/

#include "../include/solver.h"

maze_t *free_close_return(FILE *file, maze_t *maze_struct)
{
    free(maze_struct);
    fclose(file);
    return ((maze_t *)-1);
}

maze_t *free_return_maze(maze_t *maze_struct)
{
    if (maze_struct)
        free(maze_struct);
    return ((maze_t *)-1);
}