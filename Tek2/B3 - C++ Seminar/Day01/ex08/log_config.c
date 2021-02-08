/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** log_config
*/

#include "log.h"

FILE *log_output(FILE *log_output)
{
    static FILE *current_output = NULL;

    if (log_output != NULL)
        current_output = log_output;

    return (current_output);
}

enum log_level set_log_level(enum log_level new_level)
{
    static enum log_level current_level = ERROR;

    if (new_level != -1 && DEBUG <= new_level && new_level <= ERROR)
        current_level = new_level;

    return (current_level);
}

enum log_level get_log_level(void)
{
    return (set_log_level(-1));
}

int close_log_file(void)
{
    if (log_output(NULL) == NULL || log_output(NULL) == stdout
    || log_output(NULL) == stderr)
        return (0);
    if (fclose(log_output(NULL)))
        return (1);
    log_output(stderr);

    return (0);
}

int set_log_file(const char *name)
{
    if (close_log_file())
        return (1);
    if (!log_output(fopen(name, "a")))
        return (1);

    return (0);
}