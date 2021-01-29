/*
** EPITECH PROJECT, 2020
** asm
** File description:
** core_struct
*/

#ifndef CORE_STRUCT_H_
#define CORE_STRUCT_H_

typedef struct label_s
{
    char const *name;
    u_int32_t position;
    struct label_s *next;
} label_t;

typedef struct cor_s
{
    u_int32_t head;
    header_t *header;
    char *code;
    label_t *label_list;
} cor_t;


typedef union argument_u
{
    int8_t r;
    int16_t d;
    int32_t i;
} argument_t;

typedef struct instruction_s
{
    argument_t arg[MAX_ARGS_NUMBER];
    u_int8_t arg_tab[MAX_ARGS_NUMBER];
} instruction_t;


#endif /* !CORE_STRUCT_H_ */
