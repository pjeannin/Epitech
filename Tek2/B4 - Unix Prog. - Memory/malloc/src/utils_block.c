/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** utils
*/

#include "../include/my_malloc.h"

block_t *find_equal(block_t *block, void *to_compare)
{
    if (!to_compare)
        return (NULL);
    for (; block; block = block->next)
        if (block->address == to_compare)
            return (block);

    return (NULL);
}

static block_t *split_block(size_t size, block_t *block)
{
    int total = block->pos - size;
    void *tmp = block->next;

    block->pos = size;
    block->free = !block->free;
    block->next = block->address + size;
    block->next->address = block->next + sizeof(block_t);
    block->next->pos = total;
    block->next->next = tmp;
    block->next->prev = block;
    block->next->free = true;

    return (block);
}

block_t *find_empty_block(size_t size, block_t *block)
{
    block_t *tmp = NULL;

    if (!block)
        return (NULL);
    for (; block; block = block->next) {
        if (block->free && block->pos == size)
            return (block);
        else if (block->free && block->pos > size && (!tmp || tmp->pos > block->pos))
            tmp = block;
    }
    if (tmp)
        return (tmp->pos > size + sizeof(block_t) + 1 ? split_block(size, tmp) : tmp);

    return (NULL);
}

void block_cpy(block_t *from, block_t *to)
{
    size_t *ptrTo = (size_t *)to->address;
    size_t *ptrFrom = (size_t *)from->address;

    for (int i = 0; i * sizeof(size_t) < from->pos && i * sizeof(size_t) <
    to->pos; ++i)
        ptrTo[i] = ptrFrom[i];
}