/*
** EPITECH PROJECT, 2019
** put_all_nbr.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>

int __put_nbr(long long nbr, int len);
char *base_convert(int nbr, char *base, int base_len);

int my_putstr(char *str)
{
    int len = 0;

    while (*str) {
        write(1, str++, 1);
        ++len;
    }
    return (len);
}

int put_unsigned_int(va_list list, char *format, int len_indicator)
{
    long long nbr = va_arg(list, long long);

    if (nbr < 0)
        nbr = 4294967296 - nbr;
    return (__put_nbr(nbr, 0));
}

int put_octal(va_list list, char *format, int len_indicator)
{
    long long nbr = va_arg(list, long long);

    if (nbr < 0)
        nbr = 4294967296 - nbr;
    char *nb = base_convert(nbr, "01234567", 8);
    if (*format == '#')
        write(1, "0", 1);
    return (my_putstr(nb));
}

int put_binary(va_list list, char *format, int len_indicator)
{
    long long nbr = va_arg(list, long long);

    if (nbr < 0)
        nbr = 4294967296 - nbr;
    char *nb = base_convert(nbr, "01", 2);
    return (my_putstr(nb));
}

int put_hexa_low(va_list list, char *format, int len_indicator)
{
    long long nbr = va_arg(list, long long);

    if (nbr < 0)
        nbr = 4294967296 - nbr;
    char *nb = base_convert(nbr, "0123456789abcdef", 16);
    if (*format == '#')
        write(1, "0x", 2);
    return (my_putstr(nb));
}