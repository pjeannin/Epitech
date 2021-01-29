/*
** EPITECH PROJECT, 2020
** char_form_int.c
** File description:
** my_ls
*/

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

char *char_from_int(int nbr)
{
    int cpy = nbr;
    int len = 0;
    int i = 0;
    char *n;

    while (cpy > 0) {
        ++len;
        cpy /= 10;
    }
    if (len == 0)
        return("0");
    n = malloc(sizeof(char) * len);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    str_rev(n);
    return (n);
}