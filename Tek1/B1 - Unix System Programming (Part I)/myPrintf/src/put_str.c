/*
** EPITECH PROJECT, 2019
** put_str.c
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

char *base_convert(int nbr, char *base, int base_len);
int my_putstr(char *str);

int put_char(va_list list, char *format, int len_indicator)
{
    int c = va_arg(list, int);

    write(1, &c, 1);
    return (1);
}

int put_str(va_list list, char *format, int len_indicator)
{
    char *str = va_arg(list, char *);
    char *nbr;
    int len = 1;

    while (*str) {
        if (*str < 32 || *str >= 127) {
            write(1, "\\", 1);
            nbr = base_convert((int)*str, "01234567", 8);
            if (*str < 32) {
                ++len;
                write(1, "0", 1);
            }
            len += my_putstr(nbr);
            ++str;
        } else {
        write(1, str++, 1);
        }
    }
    return (len);
}