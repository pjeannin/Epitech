/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_input
*/

#include "get_input.h"
#include "my.h"

input_list_t *read_input(void)
{
    char *buf = NULL;
    input_list_t *input_list = init_input_list();
    size_t n = 0;

    if (!input_list)
        return ((input_list_t *) - 1);
    while (getline(&buf, &n, stdin) != -1) { 
        if (input_list->line) {
            input_list->next = init_input_list();
            if (!input_list->next)
                return ((input_list_t *) - 1);
            input_list->next->prev = input_list;
            input_list = input_list->next;
        }
        input_list->line = my_strdup(buf);
        if (buf[my_strlen(buf) - 1] == '\n')
            input_list->line[my_strlen(buf) - 1] = '\0';
    }
    return (input_list);
}

char **transform_input(char **input, input_list_t *input_list, int len)
{
    for (int i = 0; i < len; ++i) {
        if (input_list->line[0] == '#' && input_list->line[1] != '#') {
            --i;
            --len;
        } else
            input[i] = input_list->line;
        input_list = input_list->next;
    }
    input[len] = NULL;
    return (input_list);
}

char **get_input(void)
{
    char **input;
    int len = 1;
    input_list_t *input_list = read_input();;

    if (!input_list)
        return ((char **)-1);
    for (; input_list->next; input_list = input_list->next);
    for (; input_list->prev; input_list = input_list->prev)
        ++len;
    input = malloc(sizeof(char *) * (len + 2));
    if (!input)
        return ((char **) - 1);
    input = transform_input(input, input_list, len);
    return (input);
}