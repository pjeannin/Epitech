/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Write a function that returns a number, sent to the function as a string
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;
    int count_len_nbr = 0;
    int count_neg = 0;
    int is_neg = 1;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == 45)
            ++count_neg;
        ++i;
    }
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
    res *= is_neg;
    return (res);
}