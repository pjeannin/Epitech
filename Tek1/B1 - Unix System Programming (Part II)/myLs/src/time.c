/*
** EPITECH PROJECT, 2020
** time.c
** File description:
** my_ls
*/

#include <stdlib.h>
#include <time.h>

int get_day(char *date)
{
    if (date[8] == ' ')
        return (date[9] - 48);
    return ((date[8] - 48) * 10 + date[9] - 48);
}

int convert_month(char *date)
{
    if (date[4] == 'J' && date[5] == 'a')
        return (1);
    if (date[4] == 'F')
        return (2);
    if (date[4] == 'M' && date[6] == 'r')
        return (3);
    if (date[4] == 'A' && date[5] == 'p')
        return (4);
    if (date[4] == 'M' && date[6] == 'y')
        return (5);
    if (date[4] == 'J' && date[6] == 'n')
        return (6);
    if (date[4] == 'J' && date[6] == 'l')
        return (7);
    if (date[4] == 'A' && date[6] == 'g')
        return (8);
    if (date[4] == 'S')
        return (9);
    if (date[4] == 'O')
        return (10);
    if (date[4] == 'N')
        return (11);
    if (date[4] == 'D')
        return (12);
}

char *convert_time(char *date)
{
    char *disp_date = malloc(sizeof(char) * 12);
    int index = 0;

    disp_date[index] = date[8];
    ++index;
    disp_date[index] = date[9];
    ++index;
    for (int i = 3; i < 7; ++i) {
        disp_date[index] = date[i];
        ++index;
    }
    for (int i = 10; i < 16; ++i){
        disp_date[index] = date[i];
        ++index;
    }
    disp_date[index] = '\0';
    for (int i = 0; disp_date[i]; ++i)
        if (disp_date[i] >= 'A' && disp_date[i] <= 'Z')
            disp_date[i] += 32;
    return (disp_date);
}