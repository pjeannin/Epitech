/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (i == n) {
        dest[i] = '\0';
    }
    return (dest);
}
