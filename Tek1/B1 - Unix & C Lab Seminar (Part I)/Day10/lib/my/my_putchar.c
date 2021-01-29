/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** display a char
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}
