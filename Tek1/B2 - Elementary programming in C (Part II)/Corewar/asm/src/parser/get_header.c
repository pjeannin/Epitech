/*
** EPITECH PROJECT, 2020
** get_header
** File description:
** get_header
*/

#include "includes.h"

static bool filling_header_struct(char const *line, header_t *header,
                           unsigned char const count)
{
    char *i = ((count == name_e) ? (header->prog_name) : (header->comment));
    char const *end = i + (((count == name_e) ? (PROG_NAME_LENGTH) : (COMMENT_LENGTH)) - my_strlen_crt(line, '"'));

    for (++line; *line != '"'; ++line, ++i)
        *i = *line;
    for (; i != end; ++i)
        *i = 0;
    return (false);
}

header_t *get_header(FILE *file)
{
    char *line = malloc(50);
    size_t size = 0;
    unsigned char count = 0;
    char header_info[2][10] = {{NAME_CMD_STRING}, {COMMENT_CMD_STRING}};
    header_t *header = malloc(sizeof(header_t));

    while (count <= 1 && getline(&line, &size, file) != -1)
    {
        skip_flag(&line, " \t", 0, true);
        printf("%s\n", line);
        if (*line == COMMENT_CHAR)
            continue;
        else if (*line == '.' && my_strcomp(line, header_info[count]) == 0)
        {
            filling_header_struct(line + my_strlen_crt(line, '"'),
                                  header, count);
            ++count;
        }
    }
    printf("[%s] [%s]\n", header->prog_name, header->comment);
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = PROG_NAME_LENGTH + COMMENT_LENGTH;
    return (header);
}