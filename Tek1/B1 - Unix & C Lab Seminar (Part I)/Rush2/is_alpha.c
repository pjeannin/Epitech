/*
** EPITECH PROJECT, 2019
** is_alpha
** File description:
** is_alpha
*/

int is_alpha(char str)
{
    int res = 1;

    if (str >= 65 && str <= 90 || str >= 97 && str <= 122)
        res = 1;
    else
        return (0);
    return (res);
}
