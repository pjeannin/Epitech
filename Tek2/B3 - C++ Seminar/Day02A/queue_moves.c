/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** queue_moves
*/

#include <stdlib.h>
#include "queue.h"

bool queue_push(queue_t *queue_ptr , void *elem)
{
    return (list_add_elem_at_front(queue_ptr, elem));
}

bool queue_pop(queue_t *queue_ptr)
{
    queue_t queue = *queue_ptr;

    if (!queue || !queue->next)
        return (false);
    *queue_ptr = queue->next->next;
    free(queue->next);

    return (true);
}