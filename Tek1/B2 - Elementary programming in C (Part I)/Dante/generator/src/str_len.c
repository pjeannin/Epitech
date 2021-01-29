/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** str_len
*/

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}