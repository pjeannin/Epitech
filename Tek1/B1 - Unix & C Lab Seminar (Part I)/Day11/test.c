/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/
#include "include/mylist.h"
#include<stdlib.h>

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *list = NULL;
    struct linked_list *element;

    for (int i = 0; i < ac; ++i) {
        element = malloc(sizeof(*element));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *tmp;
    int count = 0;

    tmp = begin;
    while (tmp != NULL){
        ++count;
        tmp = tmp->next;
    }
    return (count);
}

void show(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

void my_rev_list(linked_list_t **begin)
{
    struct linked_list *l1 = NULL;
    struct linked_list *l2;
    struct linked_list *l3;

    l2 = *begin;
    while (l2 != NULL) {
        l3 = l2->next;
        l2->next = l1;
        l1 = l2;
        l2 = l3;
    *begin = l1;
    }
}

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *list;

    list = begin;
    while (list != NULL) {
        f(list->data);
        list = list->next;
    }
}

int comp(char *s1, char *s2)
{
    int res = 0;
    int i = 0;

    while (s1[i] != '\0' ||  s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            res = 1;
            return (res);
        }
        if (s1[i] < s2[i]) {
            res = -1;
            return (res);
        }
        ++i;
    }
    if (s1[i] != '\0' &&  s2[i] == '\0' || s1[i] == '\0' && s2[i] != '\0')
        res = 0;
    return (res);
}

int aff_str(char *str)
{
    my_putstr(str);
    my_putchar('\n');
}

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(), 
                        void const *data_ref, int (*cmp) () )
{
    linked_list_t *list;
    int match;

    list = begin;
    while (list != NULL) {
        if (cmp(data_ref, list->data) == 0)
            f(list->data);
        list = list->next;
    }
}

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref,
                            int (*cmp)())
{
    linked_list_t *list;

    list = begin;
    while (list != NULL) {
        if (cmp(data_ref, list->data) == 0)
            return (list);
        list = list->next;
    }
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *list;
    linked_list_t *delete;

    list = *begin;
    while (list != NULL) {
        if (list->next == NULL)
            return (0);
        delete = list->next;
        if (cmp(data_ref, delete->data) == 0) {
            list->next = delete->next;
        }
        if (cmp(data_ref, list->data) == 0)
            *begin = list->next;
        list = list->next;
    }
    return (0);
}

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *list;

    list = *begin1;
    while (1 == 1) {
        if (list->next == NULL) {
            list->next = begin2;
            return;
        }
        list = list->next;
    }
}

void new_list(linked_list_t **list, char *str)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = str;
    element->next = *list;
    *list = element;
}

int sort(linked_list_t *list, int (*cmp)())
{
    int ok = 0;
    char *l2;

    while (list->next != NULL) {
        if (cmp(list->data, (list->next)->data) == 1) {
            ok =1;
            l2 = list->data;
            list->data = (list->next)->data;
            (list->next)->data = l2;
        }
        list = list->next;
    }
    return (ok);
}


void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    int ok = 1;
    linked_list_t *list;


    list = *begin;
    while (ok != 0) {
        ok = sort(list, cmp);
    }
}

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *element;
    linked_list_t *list;

    list = *begin;
    element  = malloc(sizeof(*element));
    element->data = data;
    while (cmp(data, (list->next)->data) != -1)
        list = list->next;
    element->next = list->next;
    list->next = element;
}

int main(int ac, char **av)
{
    struct linked_list *list;
    struct linked_list **listb;
    linked_list_t *list2 = NULL;
    linked_list_t *list3 = NULL;
    linked_list_t *res;
    char *data_ref = "arg4";
    char *dat = "evil";
    int count;
    int (*f)(char *);
    int (*cmp)(char *, char *);

    new_list(&list2, "A");
    new_list(&list2, "azer");
    new_list(&list3,"jhegvkesgv");
    new_list(&list3,"sbdbdb");
    new_list(&list3,"fdsfb");
    new_list(&list3,"qgqfb");
    new_list(&list3,"gbf");
    cmp = &comp;
    f = &aff_str;
    listb = &list;
    list = my_params_to_list(ac, av);
    show(list);
    /*my_putchar('\n');
    count = my_list_size(list);
    my_put_nbr(count);
    my_putchar('\n');
    my_rev_list(listb);
    my_putchar('\n');
    my_apply_on_nodes(list, f);
    my_putchar('\n');
    my_apply_on_matching_nodes(list, f, data_ref, cmp);
    my_putchar('\n');
    res = my_find_node(list, data_ref, cmp);
    my_putstr(res->data);*/
    my_putchar('\n');
    my_delete_nodes(listb, data_ref, cmp);
    show(list);/*
    my_concat_list(listb, list2);
    show(list);
    my_rev_list(listb);
    my_putchar('\n');
    show(list);
    my_putchar('\n');
    my_sort_list(listb, cmp);
    show(list);
    my_putchar('\n');
    my_add_in_sorted_list(listb, dat, cmp);
    my_putchar('\n');
    show(list);
    my_putchar('\n');
    my_concat_list(listb, list3);
    my_sort_list(listb, cmp);
    show(list);*/
}