/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int put_str(va_list, char *, int);
int put_octal(va_list, char *, int);
int put_char(va_list, char *, int);
int put_hexa_low(va_list, char *, int);
int put_hexa_big(va_list, char *, int);
int put_nbrpf(va_list, char *, int);
int str_len(va_list);
int put_ptr(va_list, char *, int);
int put_binary(va_list, char *, int);
int put_unsigned_int(va_list, char *, int);
int my_getnbr(char **str);

int display(int index, char **str, int (**tab)(va_list, char *, int),  va_list list, int len_indicator,
        char *formatindicator)
{
    int len;

    if (index == 11) {
        write(1, *str, 1);
        len = 1;
    } else
        len = (*tab[index])(list, formatindicator, len_indicator);
    (*str)++;
    return (len);
}

int read_arg(va_list list, char **str)
{
    char *ref = "csSdiuoxXpb";
    char *form = "# +-";
    char formatindicator[5];
    int len_indicator = 0;
    int index = 0;
    int indexform = 0;
    int (*tab[11])(va_list, char *, int) = {put_char, put_str, put_str,
            put_nbrpf, put_nbrpf, put_unsigned_int, put_octal, put_hexa_low,
            put_hexa_big, put_ptr, put_binary};

    while (form[indexform] != **str && indexform < 4)
        ++indexform;
    if (**str >= '0' && **str <= '9') {
        len_indicator = my_getnbr(str);
    } else if (indexform != 4) {
        formatindicator[0] = form[indexform];
        (*str)++;
    }
    while (ref[index] != **str && index < 11)
        ++index;
    return (display(index, str, tab, list, len_indicator, formatindicator));
}

int my_printf(char *str, ...)
{
    int nbr_read_char = 0;
    char **s = &str;

    va_list(list);
    va_start(list, str);
    while (**s) {
        if (*str == '%' && str[1] != '%') {
            (*s)++;
            nbr_read_char += read_arg(list, s);
        } else if (*str == '%' && str[1] == '%') {
            write(1, (*s)++, 1);
            (*s)++;
        } else {
            write(1, (*s)++, 1);
            ++nbr_read_char;
        }
    }
    va_end(list);
    return (nbr_read_char);
}