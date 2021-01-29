/*
** EPITECH PROJECT, 2019
** cleaner.c
** File description:
** EVALEXPR IS SEXY
*/

int clean_sign(char **str)
{
    int signs = 0;
    int minus = 0;

    while ((**str == '+') || (**str == '-')) {
        if (*(*str)++ == '-')
            minus++;
        signs++;
    }
    if (signs) {
        if (minus % 2)
            return ('-');
        else
            return ('+');
    }
    return (0);
}

void clean_spaces(char *str)
{
    char *origin = str;

    while (*str) {
        if (*str != ' ')
            *origin++ = *str;
        str++;
    }
    *origin = 0;
}

void clean_operations(char *str)
{
    char *origin = str;
    char sign;

    while (*str) {
        sign = clean_sign(&str);
        if (sign)
            *origin++ = sign;
        *origin++ = *str++;
    }
    *origin = 0;
}