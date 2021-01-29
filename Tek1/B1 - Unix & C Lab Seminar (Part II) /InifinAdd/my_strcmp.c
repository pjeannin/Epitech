/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** strcmp fonction
*/

int my_strcmp(char const *s1, char const *s2)
{
    int res = 0;

    for (int i = 0; s1[i] != '\0' ||  s2[i] != '\0'; ++i) {
        if (s1[i] > s2[i]) {
            res = 1;
            return (res);
        }
        if (s1[i] < s2[i]) {
            res = -1;
            return (res);
        }
    }
    return (res);
}
