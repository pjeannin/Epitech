/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** stack_size
*/

#include <stdlib.h>
#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return (list_get_size(stack));
}

bool stack_is_empty(stack_t stack)
{
    return (list_is_empty(stack));
}