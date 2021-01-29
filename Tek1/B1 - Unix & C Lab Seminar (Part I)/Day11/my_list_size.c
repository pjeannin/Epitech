/*
** EPITECH PROJECT, 2019
** my_list_size.c
** File description:
** my_list_size
*/
#include "include/mylist.h"
#include<stdlib.h>

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