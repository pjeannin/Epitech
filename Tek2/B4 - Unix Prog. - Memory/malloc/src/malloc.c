/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** malloc
*/

#include "../include/my_malloc.h"

static block_t *first_block = NULL;

void *malloc(size_t size)
{
    block_t *current_block;

    if (!size)
        return (NULL);
    if (!first_block) {
        first_block = create_new_memory_block(size);
        if (first_block == NULL)
            return (NULL);
        return (first_block->address);
    }
    current_block = find_empty_block(size, first_block);
    if (current_block) {
        current_block->free = false;
        return (current_block->address);
    } else {
        current_block = add_block(size, first_block);
        if (!current_block)
            return (NULL);
        return (current_block->address);
    }

    return (NULL);
}

void free(void *ptr)
{
    block_t *current_block = first_block;

    if (!ptr)
        return;
    for (; current_block; current_block = current_block->next) {
        if (current_block->address == ptr && delete_block(current_block) == NULL) {
            first_block = NULL;
            return;
        } else if (current_block->address == ptr)
            return;
    }
}

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    block_t *from;
    block_t *to;

    if (!new_ptr) {
        free(ptr);
        return (new_ptr);
    } else {
        from = find_equal(first_block, ptr);
        to = find_equal(first_block, new_ptr);
        if (from && to) {
            block_cpy(from, to);
            free(ptr);
        }
        return (new_ptr);
    }

    return (NULL);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *new_ptr = calloc(nmemb, size);
    block_t *from;
    block_t *to;

    if (!new_ptr) {
        free(ptr);
        return (new_ptr);
    } else {
        from = find_equal(first_block, ptr);
        to = find_equal(first_block, new_ptr);
        if (from && to) {
            block_cpy(from, to);
            free(ptr);
        }
        return (new_ptr);
    }

    return (NULL);
}