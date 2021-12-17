/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_print
*/

#include "string.h"

void print(const string_t *this)
{
    if (!this || !this->str)
        return;
    printf("%s", this->str);
}