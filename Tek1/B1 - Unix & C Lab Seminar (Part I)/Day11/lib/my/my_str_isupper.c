/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** is a string compose with uppercase letters
*/

int my_str_isupper(char const *str)
{
    int res = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 65 && str[i] <= 90)
            res = 1;
        else
            return (0);
        }
    return (res);
}
