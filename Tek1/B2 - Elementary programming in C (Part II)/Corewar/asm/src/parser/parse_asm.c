/*
** EPITECH PROJECT, 2020
** asm
** File description:
** parse_asm
*/

#include "includes.h"

static void remove_comment(char *line)
{
    while (*line) {
        if (*line == COMMENT_CHAR) {
            *line = '\0';
            return;
        }
        ++line;
    }
}

bool parse_asm(char *line, cor_t *cor)
{

    remove_comment(line);
    if (*line == '\n')
        return (false);
    if (get_label(&line, cor))
        return (true);
    printf ("no label :%s\n", line);
    if (parse_instruction(line, cor))
        return (true);
    return (false);
}
