/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_space
*/

#include "../includes/objdump.h"

void print_space(unsigned int index, char end)
{
    if (end) {
        while (index % 16 != 0) {
            printf(" ");
            ++index;
        }
        printf("\n");
        return;
    }
    if (index % 16 != 0)
        printf(" ");
    while (index % 16 != 0) {
        printf("  ");
        ++index;
        if (index % 4 == 0 || index % 16 == 0)
            printf(" ");
    }
}