/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** minishell1
*/

int neg(int *pi, int count_neg, char const *str)
{
    while (str[*pi] == 43 || str[*pi] == 45) {
        if (str[*pi] == 45)
            ++count_neg;
        ++(*pi);
    }
    return (count_neg);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int *pi;
    int res = 0;
    int count_len_nbr = 0;
    int count_neg = 0;
    int is_neg = 1;

    pi = &i;
    count_neg = neg(pi, count_neg, str);
    if (count_neg % 2 == 1)
        is_neg = -1;
    while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9') {
        res *= 10;
        res += str[i] - 48;
        ++i;
        ++count_len_nbr;
        if (count_len_nbr > 10)
            return (0);
    }
    return (res * is_neg);
}