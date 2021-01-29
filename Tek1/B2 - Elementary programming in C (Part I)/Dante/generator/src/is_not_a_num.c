/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** is_not_a_num
*/

int is_not_a_num(char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}