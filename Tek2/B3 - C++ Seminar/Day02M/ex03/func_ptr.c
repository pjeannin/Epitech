/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** func_ptr
*/

#include <string.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; --i)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; ++i) {
        if ('a' <= str[i] && str[i] <= 'z')
            printf("%c", (str[i] - 32));
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*actions[4])(const char *) = {print_normal, print_reverse,
    print_upper, print_42};

    if (action < PRINT_NORMAL || action > PRINT_42)
        return;
    actions[action](str);
}