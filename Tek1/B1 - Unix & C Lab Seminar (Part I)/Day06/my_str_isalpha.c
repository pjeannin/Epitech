/*
** EPITECH PROJECT, 2019
** my_str_isalpha.c
** File description:
** is a string compose with letters
*/

int my_str_isalpha(char const *str)
{
    int res = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
            res = 1;
        else
            return (0);
        }
    return (res);
}
