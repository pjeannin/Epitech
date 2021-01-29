/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for the program
*/

#include "includes.h"

static cor_t *create_binary(cor_t  *ret)
{

    return (ret);
}
//ah
static char *get_name(char *filename)
{
    int namepos = find_word(filename, count_words(filename, '/'), '/');
    char *name = NULL;

    if (str_end_w(filename, ".s"))
        name = (my_slice(filename,
                        ((filename[namepos] == '/') ? namepos + 1 : namepos),
                        my_strlen(filename) - 2));
    return (name);
}

bool process(char *filename)
{
    FILE *file = NULL;
    char *name = get_name(filename);
    cor_t *ret = NULL;

    if (!name)
        return (error(1, "incorrect file\n"));
    if (!(file = fopen(filename, "r")))
        return (error(1, "cannot open file\n"));
    ret = reader(file);
    fclose(file);
    return (ret);
}

int main(int ac, char **av)
{
    if (ac != 2 || my_strcomp(av[1], "-h"))
        return (my_putstr(1, HELP));
    return ((process(av[1])) ? 84 : 0);
}