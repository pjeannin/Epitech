/*
** EPITECH PROJECT , 2019
** my_print_revalpha.c
** File description :
** displays the lowercase alphabet in descending order
*/
#include <unistd.h>

int my_print_revalpha(void)
{
    for (char letter=122;letter>=97;letter--) {
        my_putchar (letter);
    }
    return (0);
}
