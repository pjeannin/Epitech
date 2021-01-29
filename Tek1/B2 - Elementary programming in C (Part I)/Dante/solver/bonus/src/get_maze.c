/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** get_maze
*/

#include "bonus_solver.h"

int count_line(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t n = 0;
    int nb_line = 0;

    while (getline(&line, &n, file) > 0)
        ++nb_line;
    fclose(file);
    return (nb_line);
}

maze_t *free_close_return(FILE *file, maze_t *maze_struct)
{
    free(maze_struct);
    fclose(file);
    return ((maze_t *)-1);
}

void fill_struct(maze_t *maze_struct, int nb_line)
{
    maze_struct->nb_line = nb_line;
    maze_struct->nb_col = str_len(maze_struct->maze[0]);
}

maze_t *get_maze(char *filepath)
{
    int nb_line = count_line(filepath);
    maze_t *maze_struct = malloc(sizeof(maze_t));
    FILE *file = fopen(filepath, "r");
    size_t n;

    if (maze_struct == NULL || file == NULL) {
        if (maze_struct)
            free(maze_struct);
        return ((maze_t *)-1);
    }
    maze_struct->maze = malloc(sizeof(char **) * nb_line + 1);
    if (maze_struct->maze == NULL) {
        free(maze_struct);
        return (free_close_return(file, maze_struct));
    }
    for (int i = 0; i < nb_line; ++i)
        if (getline(&(maze_struct->maze[i]), &n, file) == -1)
            return (free_close_return(file, maze_struct));
    fill_struct(maze_struct, nb_line);
    return (maze_struct);
}