/*
** EPITECH PROJECT, 2020
** check_end.c
** File description:
** matchstick
*/

int check_end(int **tab, int size)
{
    for (int i = 0; i < size; ++i) {
        if (tab[i][0] - tab[i][1] != 0)
            return (0);
    }
    return (1);
}