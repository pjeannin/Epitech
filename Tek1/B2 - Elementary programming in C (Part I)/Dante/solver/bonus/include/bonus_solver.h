/*
** EPITECH PROJECT, 2020
** solver
** File description:
** bonus_solver
*/

#include "ncurses.h"
#include "time.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BONUS_SOLVER_H_
#define BONUS_SOLVER_H_

typedef struct maze_s {
    char **maze;
    int nb_line;
    int nb_col;
} maze_t;

char *get_line(int fd);
maze_t *get_maze(char *filepath);
int str_len(char *str);
void solve(maze_t *maze_struct);
void move_right(maze_t *maze_struct, int *x, int *y);
void move_left(maze_t *maze_struct, int *x, int *y);
void move_up(maze_t *maze_struct, int *x, int *y);
void move_down(maze_t *maze_struct, int *x, int *y);
void display(maze_t *maze_struct);

#endif /* !BONUS_SOLVER_H_ */
