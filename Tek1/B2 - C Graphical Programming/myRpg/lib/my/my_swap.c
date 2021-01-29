/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
