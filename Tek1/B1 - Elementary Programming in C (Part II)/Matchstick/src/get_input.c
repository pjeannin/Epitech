/*
** EPITECH PROJECT, 2020
** get_input.c
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "matchstick.h"

int get_line(int **tab, int size, int *go)
{
    char *buf = malloc(sizeof(char) * 9);
    size_t n = 9;

    put_str("Line: ");
    buf[0] = '\0';
    while (buf[0] == '\0')
        if (getline(&buf, &n, stdin) == -1) {
            *go = 1;
            return (-1);
        }
    *go = 1;
    for (int i = 0; buf[i] != '\n'; ++i)
        if (buf[i] < '0' || buf[i] > '9')
            *go = 0;
    if (*go == 0) {
        put_str("Error: invalid input (positive number expected)\n");
        buf[0] = '\0';
    } else if (my_getnbr(buf) <= 0 || my_getnbr(buf) > size) {
        *go = 0;
        put_str("Error: this line is out of range\n");
    }
    return (my_getnbr(buf));
}

int get_matches(int **tab, int line, int *go)
{
    char *buf = malloc(sizeof(char) * 9);
    size_t n = 9;

    put_str("Matches: ");
    buf[0] = '\0';
    while (buf[0] == '\0')
        if (getline(&buf, &n, stdin) == 0)
            return (-1);
    *go = 1;
    for (int i = 0; buf[i] != '\n'; ++i)
        if (buf[i] < '0' || buf[i] > '9') {
            *go = 0;
            put_str("Error: invalid input (positive number expected)\n");
        }
    return (my_getnbr(buf));
}