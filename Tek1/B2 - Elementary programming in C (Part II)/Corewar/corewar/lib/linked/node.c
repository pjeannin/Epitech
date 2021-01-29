/*
** EPITECH PROJECT, 2020
** node
** File description:
** nodes event
*/

#include "../../include/my.h"
#include "../../include/list.h"

list_t *create_node(char *string)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL)
        return (NULL);
    new->string = my_strdup(string);
    new->next = NULL;
    return (new);
}

void free_node(list_t *node)
{
    if (node == NULL)
        return;
    if (node->string)
        freeif(node->string);
    free(node);
}
