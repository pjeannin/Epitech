/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** reverse a string
*/

int str_len(char const *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

void str_rev(char *str)
{
    int i = 0;
    int j = (str_len(str) - 1);
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}
