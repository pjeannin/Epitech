/*
** EPITECH PROJECT, 2020
** list.h
** File description:
** linked lists
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list_s
{
    char *string;
    struct list_s *next;
} list_t;

// nodes
list_t *create_node(char *string);
void free_node(list_t *node);

// list_utils
unsigned int list_len(list_t *list);
void list_print(list_t *list);
void list_free(list_t *list);

// list_actions
void list_insert(list_t **this, list_t *node, int place);
void list_append(list_t **list, list_t *node);
void list_pop(list_t **list);
void list_remove(list_t **list, int place);
list_t *list_get(list_t *list, int place);

#endif
