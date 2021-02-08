/*
** EPITECH PROJECT, 2021
** size-CPP-300-STG-3-1-CPPD01-pierre.jesizennin
** File description:
** menger
*/

#include "menger.h"

void menger(double x, double y, double size, int level)
{
    int size_empty_squsizere;

    if (level > 0) {
        size_empty_squsizere = (int) ((x + 2 * size / 3) - (x + size / 3));
        printf ("%.3d %.3d %.3d\n", size_empty_squsizere, (int) (y + size / 3),
        (int) (x + size / 3));
        menger(x, y, size / 3, level - 1);
        menger(x + size / 3, y, size / 3, level - 1);
        menger(x + 2 * size / 3, y, size / 3, level - 1);
        menger(x, y + size / 3, size / 3, level - 1);
        menger(x + 2 * size / 3, y + size / 3, size / 3, level - 1);
        menger(x, y + 2 * size / 3, size / 3, level - 1);
        menger(x + size / 3, y + 2 * size / 3, size / 3, level - 1);
        menger(x + 2 * size / 3, y + 2 * size / 3, size / 3, level - 1);
    }
}