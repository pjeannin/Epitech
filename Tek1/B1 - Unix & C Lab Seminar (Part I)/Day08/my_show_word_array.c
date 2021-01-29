/*
** EPITECH PROJECT, 2019
** my_show_word_array.c
** File description:
** show word array
*/
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab [i] != NULL;++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}