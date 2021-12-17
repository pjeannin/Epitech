/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_insert
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void process(string_t *this, size_t pos, const char *str, char *tmp)
{
    char *tmp2 = malloc(sizeof(char) * pos + 1);

    string_destroy(this);
    for (int i = 0; i < pos; ++i)
        tmp2[i] = tmp[i];
    tmp2[pos] = '\0';
    this->str = strdup(tmp2);
    this->append_c(this, str);
    free(tmp2);
    tmp2 = malloc(sizeof(char) * (strlen(tmp) - pos + 1));
    for (int i = pos; tmp[i]; ++i)
        tmp2[i - pos] = tmp[i];
    tmp2[strlen(tmp) - pos] = '\0';
    this->append_c(this, tmp2);
    free(tmp2);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp = NULL;

    if (!this || !str || pos < 0)
        return;
    tmp = strdup(this->str);
    if (pos > strlen(this->str))
        this->append_c(this, str);
    else
        process(this, pos, str, tmp);
    free(tmp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *tmp = NULL;

    if (!this || !str || !str->str || pos < 0)
        return;
    tmp = strdup(this->str);
    if (pos > strlen(this->str))
        this->append_s(this, str);
    else
        process(this, pos, str->str, tmp);
    free(tmp);
}