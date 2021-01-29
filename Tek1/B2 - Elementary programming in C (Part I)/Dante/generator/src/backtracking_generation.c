/*
** EPITECH PROJECT, 2020
** Bootstrap_dante
** File description:
** backtracking_generation
*/

#include "../include/generator.h"

void choose_direction(map_t *map_struct, int *x, int *y)
{
    switch (rand() % 5) {
        case 0: {
            move_right(map_struct, x, y);
            break;
        } case 1: {
            move_left(map_struct, x, y);
            break;
        } case 2:
            move_down(map_struct, x, y);
            break;
        default:
            move_up(map_struct, x, y);
            break;
    }
    if (no_more_move(map_struct, *x, *y))
        back_step(map_struct, x, y);
}

void generate_map(map_t *map_struct)
{
    int x = 0;
    int y = 0;

    srand(time(NULL));
    map_struct->map[y][x] = 'o';
    for (int i = 0; map_struct->map[map_struct->y - 1][map_struct->x - 1] == 'X'
    || i < 100000; ++i) {
        create_end(map_struct, &x, &y);
        choose_direction(map_struct, &x, &y);
        if (i > 10000000) {
            restart_map_generation(map_struct, &x, &y);
            i = 0;
        }
    }
}

void create_final_map(map_t *map_struct, int i, int j)
{
    if (map_struct->map[i][j] == 'o' || map_struct->map[i][j] == 'x')
        map_struct->map[i][j] = '*';
}

int generation(int x, int y, int perfect)
{
    map_t *map_struct = malloc(sizeof(map_t));

    if (!map_struct)
        return (1);
    map_struct->x = x;
    map_struct->y = y;
    map_struct->map = create_map(x, y);
    generate_map(map_struct);
    if (perfect == 0)
        create_holes(map_struct);
    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j)
            create_final_map(map_struct, i, j);
    for (int i = 0; i < y - 1; ++i)
        printf("%s\n", map_struct->map[i]);
    printf("%s", map_struct->map[y - 1]);
    return (0);
}