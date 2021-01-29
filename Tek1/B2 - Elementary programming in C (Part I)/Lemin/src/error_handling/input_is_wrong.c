/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** input_is_wrong
*/

#include "get_input.h"
#include "error_handling.h"

char **input_is_wrong(void)
{
    char **input = get_input();
    int start;
    int end;

    input = remove_comments(input);
    if (check_first_line(input) == 0)
        return (NULL);
    if (check_start_end(input, &start, &end) < 0)
        return (NULL);
    if (check_pipes(input, start, end) < 0)
        return (NULL);
    return (input);
}