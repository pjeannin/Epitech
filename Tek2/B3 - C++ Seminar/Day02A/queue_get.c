/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** queue_get
*/

#include <stdlib.h>
#include "queue.h"

void *queue_front(queue_t queue)
{
    if (queue == NULL && queue->next)
        return (0);

    return (queue->next->value);
}