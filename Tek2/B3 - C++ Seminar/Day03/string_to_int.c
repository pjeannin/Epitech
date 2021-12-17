/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_to_int
*/

#include <stdio.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return (0);
    return (atoi(this->str));
}