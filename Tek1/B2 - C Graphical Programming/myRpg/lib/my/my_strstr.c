/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** strstr
*/

#include <unistd.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    char i;

    if (str[i] != '\0') {
        i = 0;
        while (to_find[i] != str[i]) {
            return (my_strstr (str + 1, to_find));
            i++;
        }
        return (str);
    }
    else {
        return (0);
    }
}
