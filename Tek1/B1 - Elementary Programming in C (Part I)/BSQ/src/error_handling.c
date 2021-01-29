/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void check_right(struct stat file)
{
    if ((file.st_mode & S_IFMT) != S_IFREG)
        error_message("Not regular file");
    file.st_mode -= S_IFREG;
    if ((file.st_mode) % 8 != (unsigned short)7
        && (file.st_mode) % 8 != (unsigned short)6
        && (file.st_mode) % 8 != (unsigned short)4
        && (file.st_mode / 8) % 8 != (unsigned short)7
        && (file.st_mode / 8) % 8 != (unsigned short)6
        && (file.st_mode / 8) % 8 != (unsigned short)4
        && (file.st_mode / 80) % 8 != (unsigned short)7
        && (file.st_mode / 80) % 8 != (unsigned short)6
        && (file.st_mode / 80) % 8 != (unsigned short)4)
        error_message("Not right acces");
}

int read_size(int fd, char *buf)
{
    int nb_line = 0;
    int rd = 1;

    while (rd) {
        read(fd, buf, 1);
        if (*buf == '\n')
            rd = 0;
        else if (*buf >= '0' && *buf <= '9') {
            nb_line *= 10;
            nb_line += *buf - 48;
        } else
            error_message("File is not a map");
    }
    return (nb_line);
}

void check_line_col(char *buf, int *c_line, int *c_col, int *size_col,
                    int nb_line)
{
    ++(*c_col);
    if ((*c_line > 0 && *c_line < nb_line && *buf == '\n' && (*c_col > *size_col || *c_col < *size_col)))
        error_message("File is not a map");
    if (*buf == '\n') {
        if (*c_line == 0)
            *size_col = *c_col;
        *c_col = 0;
        ++(*c_line);
    }
}

void check_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int c_line = 0;
    int c_col = 0;
    int size_col = 0;
    int nb_line = 0;
    int rd = 1;
    char *buf = malloc(sizeof(char));
    char prev;

    nb_line = read_size(fd, buf);
    while (rd) {
        rd = read(fd, buf, 1);
        if (*buf != '.' && *buf != 'o' && *buf != '\n')
            error_message("File is not a map");
        check_line_col(buf, &c_line, &c_col, &size_col, nb_line);
        prev = *buf;
    }
    if (prev != '\n' || ((nb_line) + 1 != c_line))
        error_message("File is not a map");
}

void error_handling(char *filepath)
{
    struct stat file;
    char *buf = malloc(sizeof(char));
    int fd;

    stat(filepath, &file);
    check_right(file);
    if (file.st_size == 0)
        error_message("Empty file");
    check_map(filepath);
}