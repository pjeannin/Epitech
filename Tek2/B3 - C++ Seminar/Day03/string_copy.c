/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_copy
*/

#include <string.h>
#include "string.h"


size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t index = 0;

    if (!this || !this->str || !s)
        return (0);
    for (int i = 0; this->str[i]; ++i) {
        if (i == pos) {
            for (; this->str[i] && index < n; ++i)
                s[index++] = this->str[i];
            s[index] = '\0';
        }
    }

    return (index);
}