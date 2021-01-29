/*
** EPITECH PROJECT, 2020
** HEADER FOR THE corewar
9** File description:
** header file for the corewar
*/

#include "core_struct.h"

#ifndef CORE_FUNC_H_
#define CORE_FUNC_H_

#define NEXT(thing) thing = thing->next
enum header_e{name_e, header_e};

/* aled */
cor_t *reader(FILE *file);

/* parser */
bool parse_asm(char *line, cor_t *cor);
bool get_label(char **line, cor_t *cor);
header_t *get_header(FILE *file);
bool parse_instruction(char *line, cor_t *cor);

bool get_label_offset(char *line, int *value, cor_t *cor);

/* process */
bool add_new_label(label_t **current, char const *name, u_int32_t position);

/* utilities */
bool skip_flag(char **str, char const *flag, char const end, bool const end_);

#endif
