/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** log
*/

#ifndef LOG_H_
#define LOG_H_

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

enum log_level { DEBUG , INFO , NORICE , WARNING , ERROR };

FILE *log_output(FILE *log_output);
enum log_level set_log_level(enum log_level new_level);
enum log_level get_log_level(void);
int close_log_file(void);
int set_log_file(const char *name);

#endif /* !LOG_H_ */
