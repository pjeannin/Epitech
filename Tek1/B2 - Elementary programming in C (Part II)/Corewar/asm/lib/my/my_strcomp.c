/*
** EPITECH PROJECT, 2019
** my_strcompt
** File description:
** my_strcomp
*/

#include "../../include/my.h"

int my_strcomp(char const *string, char const *testr)
{
    if (*string != *testr)
        return (0);
    if (my_strlen(string) != my_strlen(testr))
        return (0);
    while (*string)
        if (*string++ != *testr++)
            return (0);
    return (1);
}

bool my_strcompe(char const *string, char const *testr)
{
    while (*string && *testr) {
        if (*string++ != *testr++)
            return (false);
    }
    return (true);
}

char strcmp_crt(char const *s1, char const *s2, char const crt)
{
    for (; *s1 && *s2 && *s1 == *s2 && *(s1 + 1) != crt &&
    *(s2 + 1) != crt; ++s1, ++s2);
    return (*s1 - *s2);

}
