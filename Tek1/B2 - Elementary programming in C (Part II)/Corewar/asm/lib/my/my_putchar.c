/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** display a char
*/

#include "../../include/my.h"

int my_putchar(int fd, char c)
{
    write(fd, &c, 1);
    return (0);
}
