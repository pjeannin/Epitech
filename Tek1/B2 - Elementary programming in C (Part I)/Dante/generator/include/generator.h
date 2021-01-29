/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** genrator
*/

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef GENRATOR_H_
#define GENRATOR_H_

typedef struct map_s {
    char **map;
    int x;
    int y;
} map_t;

int is_not_a_num(char *str);
int error_handling(int ac, char **av);
int str_comp(char *str1, char *str2);
int str_len(char *str);
int generation(int x, int y, int perfect);
void back_step(map_t *map_struct, int *x, int *y);
int no_more_move_end(map_t *map_struct, int x, int y);
int no_more_move(map_t *map_struct, int x, int y);
void move_right(map_t *map_struct, int *x, int *y);
void move_left(map_t *map_struct, int *x, int *y);
void move_up(map_t *map_struct, int *x, int *y);
void move_down(map_t *map_struct, int *x, int *y);
void create_holes(map_t *map_struct);
char **create_map(int x, int y);
char **free_map(char **map, int i);
void restart_map_generation(map_t *map_struct, int *x, int *y);
void create_end(map_t *map_struct, int *x, int *y);

#endif /* !GENRATOR_H_ */
