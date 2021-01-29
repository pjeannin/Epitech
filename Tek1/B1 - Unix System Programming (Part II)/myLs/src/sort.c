/*
** EPITECH PROJECT, 2020
** sort.c
** File description:
** my_ls
*/

#include "my_ls.h"

int is_not_sort(file_t *list)
{
    list = move_beginning(list);
    while(list->next) {
        if (comp_str(list->name, list->next->name) < 0)
            return (1);
        list = list->next;
    }
    return (0);
}

file_t *sort(file_t *list)
{
    while (is_not_sort(list)) {
        list = move_beginning(list);
        while (list->next) {
            if (comp_str(list->name, list->next->name) == -1)
                list = swap_node(list);
            list = list->next;
        }
    }
    return (move_beginning(list));
}

int comp_time(char *t1, char *t2)
{
    int year1 = my_getnbr(&t1[20]);
    int year2 = my_getnbr(&t2[20]);
    int month1 = convert_month(t1);
    int month2 = convert_month(t2);
    int day1 = get_day(t1);
    int day2 = get_day(t2);
    int h1 = (t1[11] - 48) * 10 + t1[12] - 48;
    int h2 = (t2[11] - 48) * 10 + t2[12] - 48;
    int m1 = (t1[14] - 48) * 10 + t1[15] - 48;
    int m2 = (t2[14] - 48) * 10 + t2[15] - 48;
    int s1 = (t1[17] - 48) * 10 + t1[18] - 48;
    int s2 = (t2[17] - 48) * 10 + t2[18] - 48;

    if (year1 < year2)
        return (-1);
    if (year2 < year1)
        return (1);
    if (month1 < month2)
        return (-1);
    if (month1 > month2)
        return (1);
    if (day1 < day2)
        return (-1);
    if (day1 > day2)
        return (1);
    if (h1 < h2)
        return (-1);
    if (h1 > h2)
        return (1);
    if (m1 < m2)
        return (-1);
    if (m1 > m2)
        return (1);
    if (s1 < s2)
        return (-1);
    if (s1 > s2)
        return (1);
    return (0);
}

int is_not_asort(file_t *list)
{
    list = move_beginning(list);
    while(list->next) {
        if (comp_time(list->a_time_brut, list->next->a_time_brut) < 0)
            return (1);
        list = list->next;
    }
    return (0);
}

file_t *sort_a_time(file_t *list)
{
    while (is_not_asort(list)) {
        list = move_beginning(list);
        while (list->next) {
            if (comp_time(list->a_time_brut, list->next->a_time_brut) < 0)
                list = swap_node(list);
            list = list->next;
        }
    }
    return (move_beginning(list));
}
