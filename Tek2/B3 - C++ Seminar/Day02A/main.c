/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** main
*/

#include <stdlib.h>
#include "double_list.h"
#include "generic_list.h"
#include "queue.h"

static void populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_front(list_head, 5.2);
    double_list_add_elem_at_back(list_head, 653);
}

static void test_size(double_list_t list_head)
{
    printf("There are %u elements in the list\n", double_list_get_size(list_head));
    double_list_dump(list_head);
}

static void test_del(double_list_t *list_head)
{
    double_list_del_elem_at_back(list_head);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_add_elem_at_front(list_head, 6);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_del_elem_at_front(list_head);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_add_elem_at_front(list_head, 657);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_del_elem_at_position(list_head, 1);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_add_elem_at_position(list_head, 1.57, 1);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
    double_list_del_elem_at_front(list_head);
    printf("There are %u elements in the list\n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
}

int main(void)
{
    double_list_t list_head = NULL;

    populate_list(&list_head);
    test_size(list_head);
    test_del(&list_head);

    return (0);
}