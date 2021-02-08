/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_append
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = NULL;

    if (!this || !ap || !ap->str)
        return;
    if (!this->str) {
        this->str = strdup(ap->str);
    } else {
        tmp = strdup(this->str);
        string_destroy(this);
        this->str = malloc(sizeof(char) * (strlen(tmp) + strlen(ap->str) + 1));
        for (int i = 0; tmp[i]; ++i)
            this->str[i] = tmp[i];
        for (int i = 0; ap->str[i]; ++i)
            this->str[strlen(tmp) + i] = ap->str[i];
        this->str[strlen(tmp) + strlen(ap->str)] = '\0';
    }
    free(tmp);
}

void append_c(string_t *this, const char *s)
{
    char *tmp = NULL;

    if (!this || !s)
        return;
    if (!this->str) {
        this->str = strdup(s);
    } else {
        tmp = strdup(this->str);
        string_destroy(this);
        this->str = malloc(sizeof(char) * (strlen(tmp) + strlen(s) + 1));
        for (int i = 0; tmp[i]; ++i)
            this->str[i] = tmp[i];
        for (int i = 0; s[i]; ++i)
            this->str[strlen(tmp) + i] = s[i];
        this->str[strlen(tmp) + strlen(s)] = '\0';
    }
    free(tmp);
}