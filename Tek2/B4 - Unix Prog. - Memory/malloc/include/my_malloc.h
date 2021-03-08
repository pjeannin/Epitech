/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-pierre.jeannin
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct block_s {
    bool free;
    void *address;
    size_t pos;
    struct block_s *next;
    struct block_s *prev;
} block_t;

block_t *find_equal(block_t *block, void *to_compare);
block_t *find_empty_block(size_t size, block_t *block);
void block_cpy(block_t *from, block_t *to);
block_t *add_block(size_t size, block_t *block);
void *create_new_memory_block(size_t size);
block_t *delete_block(block_t *block);
int find_upper_power_of_two(int number);

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb , size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MY_MALLOC_H_ */
