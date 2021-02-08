/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** pyramid
*/

int retrun_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int pyramid_path(int size, const int **map, int x, int y)
{
    if (y == size - 1)
        return (map[y][x]);
    return (map[y][x] + retrun_min(pyramid_path(size, map, x, y + 1),
    pyramid_path(size, map, x + 1, y + 1)));
}