/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_input
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef GET_INPUT_H_
#define GET_INPUT_H_

typedef struct input_list_s {
    char *line;
    struct input_list_s *next;
    struct input_list_s *prev;
} input_list_t;

char **get_input(void);
input_list_t *init_input_list(void);

#endif /* !GET_INPUT_H_ */
