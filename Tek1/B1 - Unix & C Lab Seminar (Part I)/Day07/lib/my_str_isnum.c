/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** is a string compose with numbers
*/

int my_str_isnum(char const *str)
{
    int res = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 48  && str[i] <= 57)
            res = 1;
        else
            return (0);
        }
    return (res);
}
