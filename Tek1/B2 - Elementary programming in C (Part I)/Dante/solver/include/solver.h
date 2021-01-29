/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct maze_s {
    char **maze;
    int nb_line;
    int nb_col;
} maze_t;

char *get_line(int fd);
maze_t *get_maze(char *filepath);
int str_len(char *str);
maze_t *solve(maze_t *maze_struct);
void move_right(maze_t *maze_struct, int *x, int *y);
void move_left(maze_t *maze_struct, int *x, int *y);
void move_up(maze_t *maze_struct, int *x, int *y);
void move_down(maze_t *maze_struct, int *x, int *y);
maze_t *free_close_return(FILE *file, maze_t *maze_struct);
maze_t *free_return_maze(maze_t *maze_struct);

#endif /* !SOLVER_H_ */
