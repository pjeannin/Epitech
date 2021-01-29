/*
** EPITECH PROJECT, 2019
** my_str_toword_array.c
** File description:
** 103cipher
*/

#include <stdlib.h>
#include <unistd.h>
#include "103cypher.h"

int is_alpha_or_num(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return (1);
    return (0);
}

int nb_word(char const*str)
{
    int cut = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_alpha_or_num(str[i]) == 0)
            ++cut;
    }
    return (cut);
}

int add_to_tab(char const *str, char **tab, int ptab, int i)
{
    int len = 0;
    int count = i;
    int isalnum = 1;

    isalnum = is_alpha_or_num(str[count]);
    while (isalnum == 1) {
        ++count;
        isalnum = is_alpha_or_num(str[count]);
        ++len;
    }
    if (len != 0) {
        tab[ptab] = malloc(sizeof(char) * len);
        if (tab[ptab] == NULL)
            return(-1);
        for (int j = 0; j < len; ++j)
            tab[ptab][j] = str[i + j];
        ++ptab;
    }
    return (ptab);
}

char **my_str_to_word_array(char const *str, int *cut)
{
    int ptab = 0;
    char **tab;
    char *tmp;

    *cut = nb_word(str);
    tab = malloc(sizeof(char *) * (*cut));
    if (tab == NULL)
        return (NULL);
    ptab = add_to_tab(str, tab, ptab, 0);
    for (int i = 0; i < str_len(str); ++i) {
        if (is_alpha_or_num(str[i]) == 0) {
            ++i;
            ptab = add_to_tab(str, tab, ptab, i);
        }
    }
    return (tab);
}