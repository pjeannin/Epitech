/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char **hande_tilde(char **tab,env_t **env_list)
{
    for (int i = 0; tab[i]; ++i)
        if (tab[i][0] == '~')
            tab[i] = concat_str(find_val(env_list, "HOME"), &tab[i][1]);
    return (tab);
}

int is_alpha_or_num(char c)
{
    if (c  != ' ' && c != '\t')
        return (1);
    return (0);
}

int nb_word(char *str)
{
    int cut = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_alpha_or_num(str[i]) == 0)
            ++cut;
    }
    return (cut);
}

int add_to_tab(char *str, char **tab, int ptab, int i)
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
            return (-1);
        for (int j = 0; j < len; ++j)
            tab[ptab][j] = str[i + j];
	tab[ptab][len] = '\0';
    ++ptab;
    }
    return (ptab);
}

char **create_word_list(char *str, env_t **env_list)
{
    int cut;
    int ptab = 0;
    char **tab;
    char *tmp;

    cut = nb_word(str);
    tab = malloc(sizeof(char *) * cut + 1);
    if (tab == NULL)
        return (NULL);
    ptab = add_to_tab(str, tab, ptab, 0);
    for (int i = 0; i < str_len(str); ++i) {
        if (is_alpha_or_num(str[i]) == 0) {
            ++i;
            ptab = add_to_tab(str, tab, ptab, i);
        }
    }
    tab[ptab] = NULL;
    return (hande_tilde(tab, env_list));
}
