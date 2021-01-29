/*
** EPITECH PROJECT, 2020
** comp_str.c
** File description:
** my_ls
*/

int comp_str(char *str, char *str2)
{
    for (int i = 0; str[i] && str2[i]; ++i) {
        if (str[i] > str2[i])
            return (-1);
        if (str[i] < str2[i])
            return (1);
    }
    return (0);
}