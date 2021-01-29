/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** add n char of 2 str
*/

char *my_strncat(char *dest, char *src, int nb)
{
    int len;
    int i = 0;

    len = my_strlen(dest);
    while(src[i] != '0' && i < nb) {
        dest[len + i] = src[i];
        ++i;
    }
    dest[len + i] = '\0';
    return (dest);
}
