/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** str_utils
*/

int str_len(char *str)
{
    int len = 0;

    for (; str[len]; ++len);
    return (len);
}

int strncomp(char *str1, char *str2, int n)
{
    if (str_len(str1) < n || str_len(str2) < n)
        return (0);
    for (int i = 0; i < n; ++i)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}