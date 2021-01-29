/*
** EPITECH PROJECT, 2020
** solver
** File description:
** moves
*/

#include "bonus_solver.h"

void move_right(maze_t *maze_struct, int *x, int *y)
{
    ++(*x);
    maze_struct->maze[*y][*x] = 'o';
}

void move_left(maze_t *maze_struct, int *x, int *y)
{
    --(*x);
    maze_struct->maze[*y][*x] = 'o';
}

void move_up(maze_t *maze_struct, int *x, int *y)
{
    --(*y);
    maze_struct->maze[*y][*x] = 'o';
}

void move_down(maze_t *maze_struct, int *x, int *y)
{
    ++(*y);
    maze_struct->maze[*y][*x] = 'o';
}