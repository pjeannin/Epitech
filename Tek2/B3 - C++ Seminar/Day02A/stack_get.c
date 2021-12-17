/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** stack_show
*/

#include <stdlib.h>
#include "stack.h"

void *stack_top(stack_t stack)
{
    return (list_get_elem_at_front(stack));
}