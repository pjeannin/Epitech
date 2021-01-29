/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parse_instructions.c
*/

#include "includes.h"

bool check_next_char(char const *str, char const *flag, char const *end)
{
    for (; *str && flag_cmp(*str, flag) == true; ++str);
    return (flag_cmp(*str, end));    
}

static bool get_arg(char **line, cor_t *cor, int *value, int type)
{
    int offset = my_strlen_flag(*line, " \t,\n");
    
    if (check_next_char(*line, " \t", ",\n"))
    *(*line + offset) = 0;
    if (**line == LABEL_CHAR) {
        if (type & (T_DIR | T_IND))
            return (get_label_offset(*line, value, cor));
        else
            return (true);
    } else {
        return (false);
    }
    return (true);
}

static int8_t get_type(char **line)
{
    switch (**line) {
        case 'r':
            ++*line;
            return (T_REG);
        case DIRECT_CHAR:
            ++*line;
            //*line += ((*line)[1] == ':') ? (2) : (1));
            return (T_DIR);
        case LABEL_CHAR:
        case '0' ... '9':
            return (T_IND);
        default:
            return (0);
    }
}

static bool parse_args(char *line, cor_t *cor, op_t const *instruction)
{
    int code_size = 0;
    int type = 0;
    instruction_t code = {{{0}, {0}}};

    for (u_int32_t i = 0; i < instruction->nbr_args; ++i) {
        skip_flag(&line, " \t", 0, true);
        printf("reading arg :%s\n", line);
        if ((instruction->type[i] & (type = get_type(&line))) == 0)
            return (true);
        code.arg_tab[i] = type;
        get_arg(&line, cor, &code.arg[i].i, type);
        code_size += type;
    }
    // realloc(cor->code, sizeof(char) * (code_size + 2));
    return (false);
}

bool parse_instruction(char *line, cor_t *cor)
{
    printf ("parsing line :%s", line);
    skip_flag(&line, " \t", 0, true);
    for (u_int32_t i = 0; op_tab[i].code; ++i) {
        if (str_start_w(line, op_tab[i].mnemonique))
            return (parse_args(line + (my_strlen(op_tab[i].mnemonique) + 1),   \
                                cor, &op_tab[i]));
    }
    return (true);
}   