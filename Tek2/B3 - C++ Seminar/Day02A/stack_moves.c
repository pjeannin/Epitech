/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** stack_moves
*/

#include <stdlib.h>
#include "stack.h"

bool stack_push(stack_t *stack_ptr , void *elem)
{
    return (list_add_elem_at_front(stack_ptr, elem));
}

bool stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_front(stack_ptr));
}