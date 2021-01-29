/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solve
*/

#include "bonus_solver.h"

void end_step_back(maze_t *maze_struct, int *x, int *y)
{
    if (*x - 1 >= 0 && maze_struct->maze[*y][*x - 1] == 'o')
        --(*x);
    else if (*y - 1 >= 0 && maze_struct->maze[*y - 1][*x] == 'o')
        --(*y);
}

void step_back(maze_t *maze_struct, int *x, int *y)
{
    maze_struct->maze[*y][*x] = 'O';
    if (*x + 1 < maze_struct->nb_col && maze_struct->maze[*y][*x + 1] == 'o')
        ++(*x);
    else if (*y + 1 < maze_struct->nb_line && maze_struct->maze[*y + 1][*x]
    == 'o')
        ++(*y);
    else 
        end_step_back(maze_struct, x, y);
    maze_struct->maze[*y][*x] = 'O';
}

void move_end(maze_t *maze_struct, int *x, int *y)
{
    if (*x - 1 >= 0 && maze_struct->maze[*y][*x - 1] == '*')
        --(*x);
    else if (y - 1 >= 0 && maze_struct->maze[*y - 1][*x] == '*')
        --(*y);
    else
        step_back(maze_struct, x, y);
}

void end(maze_t *maze_struct, int x, int y)
{
    clear();
    maze_struct->maze[y][x] = 'o';
    display(maze_struct);
    getch();
    endwin();
}

void solve(maze_t *maze_struct)
{
    int x = 0;
    int y = 0;

    initscr();
    while (x != maze_struct->nb_col - 2 || y != maze_struct->nb_line - 1) {
        wclear(stdscr);
        maze_struct->maze[y][x] = 'o';
        if (x + 1 < maze_struct->nb_col && maze_struct->maze[y][x + 1] == '*')
            ++x;
        else if (y + 1 < maze_struct->nb_line && maze_struct->maze[y + 1][x] ==
        '*')
            ++y;
        else
            move_end(maze_struct, &x, &y);
        display(maze_struct);
    }
    end(maze_struct, x, y);
}