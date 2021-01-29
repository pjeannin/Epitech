/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** tab_len
*/

int tab_len(char **tab)
{
    int len = 0;

    for (; tab[len]; ++len);
    return (len);
}