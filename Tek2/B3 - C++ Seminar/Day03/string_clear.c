/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_clear
*/

#include <string.h>
#include "string.h"

void clear(string_t *this)
{
    if (!this || !this->str)
        return;
    string_destroy(this);
    this->str = strdup("");
}