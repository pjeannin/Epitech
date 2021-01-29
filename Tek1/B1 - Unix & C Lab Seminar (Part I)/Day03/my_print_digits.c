/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** displays all digits
*/

#include <unistd.h>

int my_print_digits(void)
{
    for(char number = 48 ; number <=57 ; number++) {
        my_putchar(number);
    }
    return (0);
}
