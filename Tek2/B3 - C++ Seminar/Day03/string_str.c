/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_str
*/

#include <stdlib.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this)
        return (NULL);
    return (this->str);
}