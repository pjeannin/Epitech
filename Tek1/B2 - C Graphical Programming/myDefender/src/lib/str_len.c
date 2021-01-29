/*
** EPITECH PROJECT, 2020
** concat_str.c
** File description:
** defender
*/

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}