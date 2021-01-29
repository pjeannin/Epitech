/*
** EPITECH PROJECT, 2019
** cleaner.c
** File description:
** EVALEXPR IS SEXY
*/

int clean_sign(char **str, char *ops)
{
    int signs = 0;
    int minus = 0;

    while ((**str == ops[2]) || (**str == ops[3])) {
        if (*(*str)++ == ops[3])
            minus++;
        signs++;
    }
    if (signs) {
        if (minus % 2)
            return (ops[3]);
        else
            return (ops[2]);
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

void clean_operations(char *str, char *ops)
{
    char *origin = str;
    char sign;

    while (*str) {
        sign = clean_sign(&str, ops);
        if (sign)
            *origin++ = sign;
        *origin++ = *str++;
    }
    *origin = 0;
}