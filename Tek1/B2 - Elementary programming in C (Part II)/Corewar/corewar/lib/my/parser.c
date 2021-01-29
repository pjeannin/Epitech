/*
** EPITECH PROJECT, 2020
** paser
** File description:
** take a string and transforms it into a char **
*/

#include "../../include/my.h"

int count_words(char *str, char sep)
{
    int nb_words = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == sep)
            ++i;
        if (str[i] == '\0')
            return (nb_words);
        ++nb_words;
        while (str[i] != sep && str[i] != '\0')
            ++i;
    }
    return (nb_words);
}

int get_lenght(char *str, int pos, char sep)
{
    int word_lenght = 0;
    int p = pos;

    while (str[p] == sep)
        ++p;
    while (str[pos] != sep && str[pos] != '\0') {
        ++word_lenght;
        ++pos;
    }
    return (word_lenght);
}

char *get_word(char *str, int nb, char sep)
{
    int word = 0;
    int i = 0;
    int word_lenght = 0;

    while (word < nb) {
        while (str[i] != sep && str[i] != '\0')
            ++i;
        while (str[i] == sep)
            ++i;
        ++word;
    }
    word_lenght = get_lenght(str, i, sep);
    return (my_strndup(str + i, word_lenght));
}

char **parse(char *str, char sep)
{
    int nb_words = count_words(str, sep);
    char **parsed = malloc(sizeof(char *) * (nb_words + 1));

    if (parsed == NULL)
        return (NULL);
    for (int i = 0; i < nb_words; ++i)
        parsed[i] = get_word(str, i, sep);
    parsed[nb_words] = NULL;
    return (parsed);
}
