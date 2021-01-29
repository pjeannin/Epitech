/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ai.h"

void is_end(char *str)
{
    char *info = malloc(sizeof(char) * 100);
    int i = 0;
    int index = 0;
    int ret = 0;
    int count = 0;

    for (; count < 35; ++i)
        if (str[i] == ':')
            ++count;
    for (; str[i] != '\n'; ++i)
        info[index++] = str[i];
    info[index] = '\0';
    dprintf(2, "\n\ninfo = (%s)\n\n", info);
    if (strncomp(info, "Track Cleared", 13))
        ret = 1;
    free(info);
    if (ret == 1) {
        dprintf(1, "STOP_SIMULATION\n");
        exit(0);
    }
}

void is_end_bis(char *str)
{
    char *info = malloc(sizeof(char) * 100);
    int i = 0;
    int index = 0;
    int ret = 0;
    int count = 0;

    for (; count < 3; ++i)
        if (str[i] == ':')
            ++count;
    for (; str[i] != '\n'; ++i)
        info[index++] = str[i];
    info[index] = '\0';
    dprintf(2, "\n\ninfo = (%s)\n\n", info);
    if (strncomp(info, "Track Cleared", 13))
        ret = 1;
    free(info);
    if (ret == 1) {
        dprintf(1, "STOP_SIMULATION\n");
        exit(0);
    }
}

void set_wheels(float *wheels, float val)
{
    size_t n = 0;
    char *str;

    *wheels = val;
    dprintf(1, "WHEELS_DIR:%.1f\n", *wheels);
    while (n == 0)
        getline(&str, &n, stdin);
    n = 0;
    is_end_bis(str);
}

int main(void)
{
    size_t n = 0;
    char *str;
    float wheels = 0;

    dprintf(1, "START_SIMULATION\n");
    while (n == 0)
        getline(&str, &n, stdin);
    n = 0;
    dprintf(1, "CAR_FORWARD:0.2\n");
    while (n == 0)
        getline(&str, &n, stdin);
    n = 0;
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        while (n == 0)
            getline(&str, &n, stdin);
        n = 0;
        understand_lidar(str, &wheels);
        is_end(str);
    }
}