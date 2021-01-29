/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** checks if a string is only alphanumberic
*/

#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; ++i) {
        if (!((str[i] >= 48 && str[i] <= 57)
            || (str[i] >= 65 && str[i] <= 90)
            || (str[i] >= 97 && str[i] <= 122)))
            return (0);
    }
    return (1);
}
