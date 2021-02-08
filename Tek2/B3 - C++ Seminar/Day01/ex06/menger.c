/*
** EPITECH PROJECT, 2021
** size-CPP-300-STG-3-1-CPPD01-pierre.jesizennin
** File description:
** menger
*/

#include "menger.h"
#include "drawing.h"

int error_handling(int argc, char **argv)
{
    int power = 1;

    if (argc != 4)
        return (1);
    for (int i = 0; argv[2][i]; ++i)
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (1);
    for (int i = 0; argv[3][i]; ++i)
        if (argv[3][i] < '0' || argv[3][i] > '9')
            return (1);
    if (atoi(argv[3]) == 0)
        return (1);
    for (int i = 0; i < atoi(argv[3]); ++i)
        power *= 3;
    if (atoi(argv[2]) % power)
        return (1);
    return (0);
}

unsigned int **can_continue_end(unsigned int **img, double size, int level,
point_t point)
{
    point_t new_point;

    new_point.x = point.x;
    new_point.y = point.y + 2 * size / 3;
    img = menger(new_point, size / 3, level - 1, img);
    new_point.x = point.x + size / 3;
    new_point.y = point.y + 2 * size / 3;
    img = menger(new_point, size / 3, level - 1,
    img);
    new_point.x = point.x + 2 * size / 3;
    new_point.y = point.y + 2 * size / 3;
    img = menger(new_point, size / 3, level - 1,
    img);

    return (img);
}

unsigned int **can_continue(unsigned int **img, double size, int level,
point_t point)
{
    point_t new_point;

    img = menger(point, size / 3, level - 1, img);
    new_point.x = point.x + size / 3;
    new_point.y = point.y;
    img = menger(new_point, size / 3, level - 1, img);
    new_point.x = point.x + 2 * size / 3;
    img = menger(new_point, size / 3, level - 1, img);
    new_point.x = point.x;
    new_point.y = point.y + size / 3;
    img = menger(new_point, size / 3, level - 1, img);
    new_point.x = point.x + 2 * size / 3;
    new_point.y = point.y + size / 3;
    img = menger(new_point, size / 3, level - 1,
    img);

    return (can_continue_end(img, size, level, point));
}

unsigned int **menger(point_t point, double size, int level,
unsigned int **img)
{
    int size_empty_squsizere;
    point_t new_point;

    if (level > 0) {
        new_point.x = point.x + size / 3;
        new_point.y = point.y + size / 3;
        size_empty_squsizere = (int) ((point.x + 2 * size / 3)
        - (point.x + size / 3));
        draw_square(img, new_point, size_empty_squsizere,
        (uint32_t)(255 / level) * 16 * 16 + (255 / level)
        * 16 * 16 * 16 * 16 + 255 / level);
        img = can_continue(img, size, level, point);
    }
    return (img);
}

// unsigned int **menger(point_t point, double size, int level,
// unsigned int **img)
// {
//     int size_empty_squsizere;

//     if (level > 0) {
//         size_empty_squsizere = (int) ((x + 2 * size / 3) - (x + size / 3));
//         draw_square(img, x + size / 3, y + size / 3, size_empty_squsizere,
//         (uint32_t)(255 / level) * 16 * 16 + (255 / level)
//         * 16 * 16 * 16 * 16 + 255 / level);
//         img = menger(x, y, size / 3, level - 1, img);
//         img = menger(x + size / 3, y, size / 3, level - 1, img);
//         img = menger(x + 2 * size / 3, y, size / 3, level - 1, img);
//         img = menger(x, y + size / 3, size / 3, level - 1, img);
//         img = menger(x + 2 * size / 3, y + size / 3, size / 3, level - 1,
//         img);
//         img = menger(x, y + 2 * size / 3, size / 3, level - 1, img);
//         img = menger(x + size / 3, y + 2 * size / 3, size / 3, level - 1,
//         img);
//         img = menger(x + 2 * size / 3, y + 2 * size / 3, size / 3, level - 1,
//         img);
//     }
//     return (img);
// }