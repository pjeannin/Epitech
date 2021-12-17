/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_find
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *tmp = NULL;

    if (!this || !this->str || !str || !str->str || pos > strlen(this->str) - 1
    || strlen(str->str) > strlen(this->str) - pos)
        return (-1);
    tmp = malloc(sizeof(char) * (strlen(str->str) + 1));
    for (int i = pos; this->str[i]; ++i) {
        this->copy(this, tmp, strlen(str->str), i);
        if (!strcmp(str->str, tmp)) {
            free(tmp);
            return (i);
        }
    }
    free(tmp);

    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *tmp = NULL;

    if (!this || !this->str || !str || pos > strlen(this->str) - 1
    || strlen(str) > strlen(this->str) - pos)
        return (-1);
    tmp = malloc(sizeof(char) * (strlen(str) + 1));
    for (int i = pos; this->str[i]; ++i) {
        this->copy(this, tmp, strlen(str), i);
        if (!strcmp(str, tmp)) {
            free(tmp);
            return (i);
        }
    }
    free(tmp);

    return (-1);
}