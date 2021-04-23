/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** get_ip_from_tab
*/

#include "ftp.h"

char *get_ip_from_tab(char **tab)
{
    char *str = malloc(sizeof(char) * (strlen(tab[0]) + strlen(tab[1]) +
    strlen(tab[2]) + strlen(tab[3]) + 5));
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] && i != 4) {
        while (tab[i][j]) {
            str[k++] = tab[i][j++];
        }
        str[k++] = '.';
        j = 0;
        i++;
    }
    str[k - 1] = '\0';

    return (str);
}
