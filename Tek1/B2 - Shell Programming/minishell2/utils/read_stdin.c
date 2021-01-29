/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** read_stdin
*/

#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "minishell.h"

read_t *init_read(void)
{
    read_t *read_list = malloc(sizeof(read_t));

    read_list->read = NULL;
    read_list->prev = NULL;
    read_list->next = NULL;
    return (read_list);
}

read_t *read_input(char *end_word)
{
    read_t *read_list = init_read();
    char *read = malloc(sizeof(char));
    size_t n = 0;

    read[0] = '\0';
    while (comp_str(read, end_word) == -1) {
        read[0] = '\0';
        write(1, READING_PROMPT, str_len(READING_PROMPT));
        while (read[0] == '\0')
            getline(&read, &n, stdin);
        if (read_list->read) {
            read_list->next = init_read();
            read_list->next->prev = read_list;
            read_list = read_list->next;
        }
        read_list->read = str_dup(read);
        read[str_len(read) - 1] = '\0';
    }
    return (read_list);
}

char *read_stdin(char *end_word)
{
    read_t *read_tab = read_input(end_word);
    int list_len = find_list_len(read_tab);
    char *ret_val = malloc(sizeof(char));

    ret_val = "\0";
    for (; read_tab->prev; read_tab = read_tab->prev);
    for (; read_tab->next; read_tab = read_tab->next)
        ret_val = concat_sstr(ret_val, read_tab->read);
    return (ret_val);
}