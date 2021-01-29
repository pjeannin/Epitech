/*
** EPITECH PROJECT, 2019
** put_nbr.c
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int put_nbr(long long nbr);
char *base_convert(long long nbr, char *base, int base_len);
char *base_convert_ptr(unsigned long long nbr, char *base, int base_len);
int my_putstr(char *str);

int formating(int nbr, char *format, int lennbr, int len_indicator)
{
    switch (format[0]) {
        case ' ': {
            if (nbr > 0)
            write(1, " ", 1);
            break;
        } case '+': {
            if (nbr >= 0)
            write(1, "+", 1);
            break;
        } default:
            break;
    }
    while ((len_indicator - lennbr) > 0) {
        write(1, " ", 1);
        ++lennbr;
    }
    return (lennbr);
}

int put_nbrpf(va_list list, char *format, int len_indicator)
{
    long long nbr = (long)va_arg(list, int);
    int cpy = nbr;
    int lennbr = 0;

    if (cpy < 0) {
        cpy *= -1;
        ++lennbr;
    }
    while (cpy > 0) {
        cpy /= 10;
        ++lennbr;
    }
    formating(nbr, format, lennbr, len_indicator);
    lennbr += put_nbr(nbr);
    return ((lennbr));
}

int put_hexa_big(va_list list, char *format, int len_indicator)
{
    long long nbr = va_arg(list, long long);

    if (nbr < 0)
        nbr = 4294967296 - nbr;
    char *nb = base_convert(nbr, "0123456789ABCDEF", 16);
    if (*format == '#')
        write(1, "0x", 2);
    return (my_putstr(nb));
}

int put_ptr(va_list list, char *format, int len_indicator)
{
    unsigned long long nbr = va_arg(list, unsigned long long);

    write(1, "0x", 2);
    base_convert_ptr(nbr, "0123456789abcdef", 16);
    return(14);
}