/*
** EPITECH PROJECT, 2019
** my_str_isprintable.c
** File description:
** is a string is printable
*/

int my_str_isprintable(char const *str)
{
    int res = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 32 && str[i] <= 126)
            res = 1;
        else
            return (0);
        }
    return (res);
}
