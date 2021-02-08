/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** log
*/

#include "log.h"

int log_to_stdout(void)
{
    if (close_log_file())
        return (1);
    log_output(stdout);

    return (0);
}

int log_to_stderr(void)
{
    if (close_log_file())
        return (1);
    log_output(stderr);

    return (0);
}

void log_msg(enum log_level level, const char *fmt, ...)
{
    va_list arg;
    time_t current_time;
    char *time_str;
    const char *level_str[] = {"DEBUG", "INFO", "NOTICE", "WARNING", "ERROR"};

    if (!(get_log_level() <= level && level <= ERROR))
        return;
    va_start(arg, fmt);
    current_time = time(NULL);
    time_str = ctime(&current_time);
    fprintf(log_output(NULL), "%.*s [%s]= ", (int)(strlen(time_str) - 1),
    time_str, level_str[level]);
    vfprintf(log_output(NULL), fmt, arg);
    va_end(arg);
}