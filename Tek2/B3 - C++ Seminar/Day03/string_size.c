/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_size
*/

#include <string.h>
#include "string.h"

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}