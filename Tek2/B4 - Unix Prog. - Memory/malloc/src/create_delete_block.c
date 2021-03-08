/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** create_delete_block
*/

#include <unistd.h>
#include "../include/my_malloc.h"

block_t *add_block(size_t size, block_t *block)
{
    void *address;

    size = find_upper_power_of_two(size);
    for (; block->next; block = block->next);
    address = sbrk(size + sizeof(block_t));
    if (address == (void *)-1)
        return (NULL);
    block->next = address;
    block->next->address = address + sizeof(block_t);
    block->next->free = false;
    block->next->prev = block;
    block->next->next = NULL;
    block->next->pos = size;

    return (block->next);
}

void *create_new_memory_block(size_t size)
{
    block_t *block;
    void *address;

    size = find_upper_power_of_two(size);
    address = sbrk(size + sizeof(block_t));
    if (address == (void *)-1)
        return (NULL);
    block = address;
    block->address = address + sizeof(block_t);
    block->free = false;
    block->prev = NULL;
    block->next = NULL;
    block->pos = size;

    return (block);
}

block_t *delete_block(block_t *block)
{
    block_t *current_block = block;

    block->free = true;
    for (; block->prev && block->prev->free; block = block->prev) {
        block->prev->pos += block->pos + sizeof(block_t);
        block->prev->next = block->next;
        if (block->next)
            block->next->prev = block->prev;
    }
    while (block->next && block->next->free) {
        block->pos += block->next->pos + sizeof(block_t);
        block->next->next->prev = block;
        block->next = block->next->next;
    }
    if (!block->next) {
        if (block->prev)
            block->prev->next = NULL;
        else
            current_block = NULL;
        sbrk((block->pos + sizeof(block_t)) * -1);
    }

    return (current_block);
}