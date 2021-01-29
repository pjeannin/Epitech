/*
** EPITECH PROJECT, 2020
** asm
** File description:
** reader
*/

#include "includes.h"

void reset_line(char **line)
{
    freeif(*line);
    *line = NULL;
}

cor_t *reader(FILE *file)
{
    cor_t *ret = malloc(sizeof(cor_t));
    char *line = NULL;
    size_t size = 0;
    int read = 0;

    if (!ret)
        return (NULL);
    ret->label_list = NULL;
    ret->header = get_header(file);
    ret->head = 0;
    while ((read = getline(&line, &size, file)) != -1) {
        if (parse_asm(line, ret))
            return (NULL);
    }
    free(line);
    return (ret);
}
