/*
** EPITECH PROJECT, 2020
** str_len.c
** File description:
** my_ls
*/

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}