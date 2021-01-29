/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** lidar
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ai.h"

float *read_lidar_command(char *api_ret)
{
    float *tab = malloc(sizeof(float) * 32);
    char *str = malloc(sizeof(char) * 10);
    int count = 0;
    int index = 0;
    int tab_index = 0;
    int i = 0;

    for (; count < 3; ++i)
        if (api_ret[i] == ':')
            ++count;
    count = 0;
    for (; count < 32; ++i)
        if (api_ret[i] == ':') {
            str[index] = '\0';
            index = 0;
            tab[tab_index++] = atof(str);
            ++count;
        } else
            str[index++] = api_ret[i];
    return (tab);
}

void interpret_lidar_end(float *tab, float *wheels)
{
    if (tab[0] < 500) {
        set_wheels(wheels, -0.1);
    } else if (tab[31] < 500) {
        set_wheels(wheels, 0.1);
    } else {
        set_wheels(wheels, 0);
    }
}

void interpret_lidar(float *tab, float *wheels)
{
    if (tab[0] < 300) {
        set_wheels(wheels, -0.3);
    } else if (tab[31] < 300) {
        set_wheels(wheels, 0.3);
    } else
        interpret_lidar_end(tab, wheels);
}

void understand_lidar(char *api_ret, float *wheels)
{
    float *tab = read_lidar_command(api_ret);
    char *str;
    size_t n = 0;

    if (tab[3] < 300) {
        set_wheels(wheels, -0.7);
    } else if (tab[28] < 300) {
        set_wheels(wheels, 0.7);
    } else
        interpret_lidar(tab, wheels);
    free(tab);
}