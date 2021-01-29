/*
** EPITECH PROJECT, 2019
** verifier.c
** File description:
** EVALEXPR IS SEXY
*/

int verify_operations(char *str)
{
    while (*str)
        if (((*str == '+') || (*str == '-')) &&
            ((*(str + 1) == ')') || (*(str + 1) == 0)))
            return (1);
        else
            str++;
    return (0);
}