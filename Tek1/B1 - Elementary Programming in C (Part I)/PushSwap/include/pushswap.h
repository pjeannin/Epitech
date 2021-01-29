/*
** EPITECH PROJECT, 2019
** pushswap.h
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

typedef struct linked_list {
    int nbr;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

int my_getnbr(char *);
int check_is_number(char *str);
int is_sorted(linked_list_t *list);
int error_handling(int ac, char **av);
int find_smallest(linked_list_t *list);
linked_list_t *create_linkedlist(void);
linked_list_t *sort(linked_list_t *lista);
linked_list_t *move_end(linked_list_t *list);
linked_list_t *rotate_left(linked_list_t *list);
linked_list_t *move_beginning(linked_list_t *list);
linked_list_t *arg_in_linkedlist(int size, char **av);
linked_list_t *add_nbr_to_linkedlist_end(linked_list_t *list, int nbr);
linked_list_t *add_nbr_to_linkedlist_beginning(linked_list_t *list, int nbr);
void put_nbr(int nbr);
void remove_node(linked_list_t *node);
void free_linked_list(linked_list_t *list);
void display_all_linked_list(linked_list_t *list);
void display_linked_list_all_prev(linked_list_t *list);
void display_linked_list_all_next(linked_list_t *list);
void linked_list_swap(linked_list_t *node1, linked_list_t *node2);

#endif