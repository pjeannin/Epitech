/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** add 2 str
*/

char *my_strcat(char *dest, char *src)
{
    int len;

    len = my_strlen(dest);
    for (int i = 0; src[i - 1] != '0'; ++i)
        dest[len + i] = src[i];
    return (dest);
}
