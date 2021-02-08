/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_destroy
*/

#include <stdlib.h>
#include "string.h"

void string_destroy(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
}