/*
** EPITECH PROJECT, 2019
** bonus.c
** File description:
** my_sokoban bonus
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

int my_sokoban_bonus(char *filepath)
{
    int end = 0;
    int moves = 0;
    struct stat file;
    map_t *map;
    int c = 'h';

    map = init_game_bonus(filepath);
    while (c != ' ') {
        clear();
        if (map->nbr_line <= LINES && map->nbr_col <= COLS)
            game(&c, map, &end, &moves);
        else
            mvprintw(LINES / 2, COLS / 2 - str_len(LARGE) / 2, LARGE);
        refresh();
    }
    end_game_bonus(map);
    return (end == 0 ? moves : -1);
}

void switch_choice(char *exit, int *highlight)
{
    int choice = wgetch(stdscr);

    switch (choice) {
        case KEY_UP: {
            (*highlight)--;
            if (*highlight == -1)
                *highlight = 0;
            break;
        } case KEY_DOWN: {
            (*highlight)++;
            if (*highlight == 5)
                *highlight = 4;
            break;
        } case ' ': {
            *exit = 'o';
            break;
        } default:
            break;
    }
}

void choice_screen(int *highlight, char *exit, char **choices)
{
    clear();
    for (int i = 0; i < 5; ++i) {
        if (i == *highlight)
            wattron(stdscr, A_REVERSE);
        mvwprintw(stdscr, i, COLS / 2 - str_len(choices[i]) / 2, choices[i]);
        wattroff(stdscr, A_REVERSE);
    }
    mvwprintw(stdscr, 6, COLS / 2 - str_len(SPACE) / 2, SPACE);
    switch_choice(exit, highlight);
}

char end_screen(char exit, int move)
{
    clear();
    if (move > 0) {
        mvwprintw(stdscr, 2, COLS / 2 - str_len("SCORE") / 2, "SCORE");
        mvwprintw(stdscr, 3, COLS / 2 - str_len(char_from_int(move)) / 2,
        char_from_int(move));
    } else {
        mvwprintw(stdscr, 2, COLS / 2 - str_len("Game Over") / 2, "Game Over");
        mvwprintw(stdscr, 3, COLS / 2 - str_len("Try Again") / 2, "Try Again");
    }
    mvwprintw(stdscr, 7, COLS / 2 - str_len(RESTART) / 2, RESTART);
    mvwprintw(stdscr, 8, COLS / 2 - str_len(EXIT) / 2, EXIT);
    exit = wgetch(stdscr);
    if (exit == 'r') {
        main();
        exit ='e';
    }
    return (exit);
}

void gmae_screen(char **choices, int highlight, char exit, int move)
{
    
    while (exit != 'o')
        choice_screen(&highlight, &exit, choices);
    switch (highlight) {
        case 0: {
            move = my_sokoban_bonus("../map/map1");
            break;
        } case 1: {
            move = my_sokoban_bonus("../map/big_map");
        } case 2: {
            move = my_sokoban_bonus("../map/mini_map");
            break;
        } case 3: {
            move = my_sokoban_bonus("../map/map2");
            break;
        } case 4:
            return;
    }
    while (exit != 'e')
        exit = end_screen(exit, move);
}