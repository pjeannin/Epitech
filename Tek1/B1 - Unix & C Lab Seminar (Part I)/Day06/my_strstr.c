/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** find str in a bigger str
*/

int my_strlen(char const *str);

char * comparison(char *str, char const *to_find, int i, int len)
{
    char *res;

    for (int j = 0; to_find[j] == str[i + j]; ++j) {
        if (to_find[len - 1] == str[i + j])
            res = &(str[i + j - 1 - 1]);
    }
    return (res);
}
char *my_strstr(char *str, char const *to_find)
{
    char *res;
    int len;

    if (*to_find == '\0')
        return (str);
    len = my_strlen(to_find);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (to_find[0] == str [i])
            res = comparison(str, to_find, i, len);
    }
    return (res);
}
