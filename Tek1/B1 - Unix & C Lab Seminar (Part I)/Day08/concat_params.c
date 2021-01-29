/*
** EPITECH PROJECT, 2019
** concat_params.c
** File description:
** concat param
*/
#include<stdlib.h>

char *concat_params(int argc, char **argv)
{
    char *str;
    int count = 0;

    str = malloc(sizeof(char) * (argc + 1));
    if (str == NULL)
        return (NULL);
    for (int i = 0; i < argc; ++i) {
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            str[count] = argv[i][j];
            ++count;
        }
        str[count] = '\n';
        ++count;
    }
    return (str);
}
