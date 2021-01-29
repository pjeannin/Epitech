/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** compare size of 2 string
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int res = 0;

    for (int i = 0; s1[i] != '\0' ||  s2[i] != '\0'; ++i || i < n) {
        if (s1[i] > s2[i]) {
            res = 1;
            return (res);
        }
        if (s1[i] < s2[i]) {
            res = -1;
            return (res);
        }
        return (res);
    }
}
