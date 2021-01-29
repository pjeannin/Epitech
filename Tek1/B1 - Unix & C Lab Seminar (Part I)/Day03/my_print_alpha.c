/*
** EPITECH PROJECT , 2019
** my_print_alpha.c
** File description :
** displays the lowercase alphabet in ascending order
*/
#include <unistd.h>

int my_print_alpha(void)
{
    for (char letter = 97 ; letter <= 122 ; letter++) {
        my_putchar (letter);
    }
    my_putchar ('\n');
    return(0);
}
