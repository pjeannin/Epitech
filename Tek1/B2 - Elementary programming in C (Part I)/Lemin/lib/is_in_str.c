/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** is_in_str
*/

int is_in_str(char c, char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == c)
            return (1);
    return (0);
}