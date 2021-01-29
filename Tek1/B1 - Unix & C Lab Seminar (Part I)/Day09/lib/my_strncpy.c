/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** copy n character from a str to another
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i < n || src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    if (dest[i] != '\0')
        dest[i] = '\0';
    return (dest);
}
