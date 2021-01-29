/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** display
*/

#include <ncurses.h>
#include <time.h>
#include "bonus_solver.h"

void display(maze_t *maze_struct)
{
    for (int i = 0; i < maze_struct->nb_line; ++i)
        printw(maze_struct->maze[i]);
    refresh();
    usleep(10000);
}