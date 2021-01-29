/*
** EPITECH PROJECT, 2020
** regex
** File description:
** regex.h
*/

#ifndef __REGEX_H_
#define __REGEX_H_

#include "libs.h"

typedef struct patterns_s
{
    char from;
    char to;
} patterns_t;

typedef struct regex_s
{
    patterns_t ***patterns;
    char *format;
} regex_t;

//regex
regex_t create_regex(char *expression);
int check_regex(char *str, regex_t *regex);
void destroy_regex(regex_t *regex);

//count
int count_sep(char *expression);
int count_expr(char *expression);
int count_patterns(char *expression);

//getters
patterns_t ***get_patterns(char *expression);
int get_length(char *expression);
char *get_format(char *expression);

//fillers
patterns_t *fill_patern(char *expression);
patterns_t **fill_patterns(char *expression);

//utils
int format_string(char *format, char *expression);
void free_patterns(patterns_t ***patterns);
int check_patterns(char _char, patterns_t **patterns);
int deep_checkvar(char *str, regex_t *regex, int *act_p, int *act_form);

#endif // __REGEX_H_
