/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** ptr_tricks
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int offset = ptr2 - ptr1;

    if (offset > 0)
        return (offset);
    return (offset * -1);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t strucutre;

    return ((void *)member_ptr -
    ((void *)&strucutre.member - (void *)&strucutre));
}