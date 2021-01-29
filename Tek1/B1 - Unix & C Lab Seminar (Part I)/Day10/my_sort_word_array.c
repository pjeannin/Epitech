/*
** EPITECH PROJECT, 2019
** my_sort_word_array
** File description:
** my_sort_word_array
*/
#include<stdlib.h>

int test(char **tab)
{
    char *tmp;
    int sort = 1;

    for (int i = 0; tab[i + 1] != NULL; ++i) {
        if (my_strcmp(tab[i], tab[i + 1]) == 1) {
            sort = 0;
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
        }        
    }
    return (sort);
}

int my_sort_word_array(char **tab)
{
    int sort = 0;
    while (sort != 1) {
        sort = test(tab);
    }
    return (0);
}