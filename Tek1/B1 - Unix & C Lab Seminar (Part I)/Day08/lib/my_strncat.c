/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** add n char of 2 str
*/

char *my_strncat(char *dest, char *src, int nb)
{
    int len;

    len = my_strlen(dest);
    for (int i = 0; src[i - 1] != '0' || i < nb ; ++i)
        dest[len + i] = src[i];
    return (dest);
}
