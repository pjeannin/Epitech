/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** printf but mine
*/

#include <stdarg.h>
#include "../../include/my.h"

static int pr_putc(int fd, va_list list)
{
    char print = va_arg(list, int);

    write(fd, &print, 1);
    return (1);
}

static int pr_puts(int fd, va_list list)
{
    char *str = va_arg(list, char *);
    unsigned int len = my_strlen(str);

    if (!str)
        write (fd, "(null)", 6);
    else
        write(fd, str, len);
    return (len);
}

static int pr_putd(int fd, va_list list)
{
    int nb = va_arg(list, int);
    int nbsrc;
    int div = 1;

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    nbsrc = nb;
    while (nb > 0) {
        nb /= 10;
        div *= 10;
    }
    if (div != 1) {
        for (int i = div / 10; i > 0; i /= 10)
            my_putchar(fd, ((nbsrc / i) % 10) + 48);
    } else
        my_putchar(fd, nbsrc + 48);
    return (nb);
}

static int percent(int fd, char const *format, int *k, va_list list)
{
    char *flags = "idcs%";
    int (*ptr[4])(int, va_list) = {&pr_putd, &pr_putd,
                                &pr_putc, &pr_puts};
    int i = 0;
    int ret = 0;

    for (; flags[i] != format[*k + 1] && flags[i]; ++i);
    if (i > 4)
        return (-1);
    if (flags[i] == '%')
        write(fd, "%", 1);
    else
        ret = (*ptr[i])(fd, list);
    *k += 2;
    return (ret);
}

int my_printf(int fd, char const *format, ...)
{
    va_list list;
    int k = 0;

    va_start(list, format);
    while (*format) {
        for (k = 0; format[k] != '%' && format[k]; ++k);
        write (fd, format, k);
        if (format[k] == '%')
            percent(fd, format, &k, list);
        format += k;
    }
    va_end(list);
    return (0);
}
