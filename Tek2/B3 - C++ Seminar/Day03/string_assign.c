/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_assign
*/

#include <string.h>
#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str)
        return;
    string_destroy(this);
    if (!str->str)
        this->str = NULL;
    else
        this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this)
        return;
    string_destroy(this);
    if (!s)
        this->str = NULL;
    else
        this->str = strdup(s);
}