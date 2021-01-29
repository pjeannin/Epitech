/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** my_swap
*/

int my_swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
    return (0);
}
