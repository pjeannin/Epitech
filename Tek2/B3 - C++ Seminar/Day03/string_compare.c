/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_compare
*/

#include <string.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this || !this->str || !str || !str->str)
        return (-1);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return (-1);
    return (strcmp(this->str, str));
}