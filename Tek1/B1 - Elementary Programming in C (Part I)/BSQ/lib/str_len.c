/*
** EPITECH PROJECT, 2019
** str_len.c
** File description:
** lib
*/

int str_len(char *str)
{
    int len = 0;

    while(*str++)
        ++len;
    return (len);
}