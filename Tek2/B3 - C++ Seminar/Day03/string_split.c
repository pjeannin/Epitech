/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-pierre.jeannin
** File description:
** string_split
*/

#include <string.h>
#include "string.h"

char **create_conteneur(char *str, char separator)
{
    int number = 1;
    char **return_contener = NULL;

    for (int i = 0; str[i]; ++i)
        if (str[i] == separator)
            ++number;
    return_contener = malloc(sizeof(char *) * (number + 1));
    return_contener[number] = NULL;
    for (int i = 0; i < number; ++i)
        return_contener[i] = malloc(sizeof(char) * (strlen(str) + 1));

    return (return_contener);
}

string_t **create_conteneur_s(char *str, char separator)
{
    int number = 1;
    string_t **return_contener = NULL;

    for (int i = 0; str[i]; ++i)
        if (str[i] == separator)
            ++number;
    return_contener = malloc(sizeof(string_t *) * (number + 1));
    return_contener[number] = NULL;
    for (int i = 0; i < number; ++i)
        return_contener[i] = malloc(sizeof(string_t) * (strlen(str) + 1));

    return (return_contener);
}

char **split_c(const string_t *this, char separator)
{
    char **return_contener = NULL;
    int index_tab = 0;
    int index_string = 0;

    if (!this || !this->str)
        return (NULL);
    return_contener = create_conteneur(this->str, separator);
    for (int i = 0; this->str[i]; ++i) {
        if (this->str[i] == separator) {
            return_contener[index_tab][index_string] = '\0';
            ++index_tab;
            index_string = 0;
        } else
            return_contener[index_tab][index_string++] = this->str[i];
    }
    return_contener[index_tab][index_string] = '\0';

    return (return_contener);
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **return_contener = NULL;
    char **string_tab = NULL;

    if (!this || !this->str)
        return (NULL);
    return_contener = create_conteneur_s(this->str, separator);
    string_tab = split_c(this, separator);
    for (int i = 0; string_tab[i]; ++i) {
        string_init(return_contener[i], string_tab[i]);
        free(string_tab[i]);
    }
    free(string_tab);

    return (return_contener);
}