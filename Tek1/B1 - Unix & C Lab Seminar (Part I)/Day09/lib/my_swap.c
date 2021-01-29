/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** a function that swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int d = *a;
    int c = *b;

    *b = d;
    *a = c;
}
