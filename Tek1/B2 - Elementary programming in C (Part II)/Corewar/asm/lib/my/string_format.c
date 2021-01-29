/*
** EPITECH PROJECT, 2020
** asm
** File description:
** string_format
*/

#include "../../include/my.h"

bool str_start_w(char const *str, char const *format)
{
    if (!format || !str)
        return (false);
    while (*format && *str)
        if (*str++ != *format++)
            return (false);
    return (true);
}

bool str_end_w(char const *str, char const *format)
{
    u_int32_t str_len = my_strlen(str);
    u_int32_t format_len = my_strlen(format);

    if (!format || !str)
        return (false);
    while (str_len && format_len) {
        if (format[--format_len] != str[--str_len])
            return (false);
    }
    return (true);
}