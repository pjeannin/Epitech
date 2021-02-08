/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_at
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (!this || !this->str || pos > strlen(this->str) || pos < 0)
        return (-1);
    return (this->str[pos]);
}