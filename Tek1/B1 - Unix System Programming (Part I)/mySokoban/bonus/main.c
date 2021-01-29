/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_sokoban bonus
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

int main(void)
{
    char **choices = malloc(sizeof(char *) * 4);
    int move = 0;
    int highlight = 0;
    char exit = 'n';

    for (int i = 0; i < 4; ++i)
        choices[i] = malloc(sizeof(char) * 7);
    choices[0] = "Level 1\0";
    choices[1] = "Level 2\0";
    choices[2] = "Level 3\0";
    choices[3] = "Level 4\0";
    choices[4] = "EXIT\0";
    initscr();
    keypad(stdscr, true);
    gmae_screen(choices, highlight, exit, move);
    endwin();
    return (0);
}