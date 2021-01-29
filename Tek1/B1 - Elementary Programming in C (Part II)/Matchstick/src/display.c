/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** matchstick
*/

#include "matchstick.h"

void disp(int line, int matches, char type)
{
    if (type == 'a') {
        put_str("\nAI's turn...\n");
        put_str("AI removed ");
    } else if (type == 'p') {
        put_str("\nYour turn:\n");
        put_str("Player removed ");
    }
    put_nbr(matches);
    put_str(" match(es) from line ");
    put_nbr(line);
    put_char('\n');
}