/*
** EPITECH PROJECT, 2020
** list
** File description:
** list events
*/

#include "../../include/my.h"
#include "../../include/list.h"

void list_insert(list_t **this, list_t *node, int place)
{
    list_t *mover = *this;

    if (node == NULL)
        return;
    if (place == 0 || *this == NULL) {
        node->next = *this;
        *this = node;
        return;
    }
    for (int act = 0; act < place - 1 && mover->next; ++act)
        mover = mover->next;
    node->next = mover->next;
    mover->next = node;
}

void list_append(list_t **list, list_t *node)
{
    list_t *mover = *list;

    if (*list == NULL) {
        *list = node;
        return;
    }
    while ((mover)->next)
        (mover) = (mover)->next;
    (mover)->next = node;
}

void list_pop(list_t **list)
{
    list_t *mover = *list;

    if (mover == NULL)
        return;
    else if (mover->next == NULL) {
        free_node(mover);
        *list = NULL;
        return;
    }
    while (mover->next->next)
        mover = mover->next;
    free_node(mover->next);
    mover->next = NULL;
}

void list_remove(list_t **list, int place)
{
    list_t *mover = *list;
    list_t *tmp_mover = mover;

    if (mover == NULL)
        return;
    for (int act = 0; act < place && mover->next; ++act) {
        tmp_mover = mover;
        mover = mover->next;
    }
    tmp_mover->next = mover->next;
    free_node(mover);
}

list_t *list_get(list_t *list, int place)
{
    if (list == NULL)
        return (NULL);
    for (int act = 0; list->next && act < place; ++act)
        list = list->next;
    return (list);
}

