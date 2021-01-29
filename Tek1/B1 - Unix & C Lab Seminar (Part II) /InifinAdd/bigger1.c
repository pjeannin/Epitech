/*
** EPITECH PROJECT, 2019
** bigger1.c
** File description:
** inf add
*/

#include<stdlib.h>

void my_putchar(char);
int my_strlen(char *);

char *bigger(char *nb1, char *nb2)
{
    char *nb1bis;
    char *tmp;

    for (int i = 0; nb2[i] != '\0'; ++i)
        nb2[i] = nb2[i + 1];
    nb1bis = malloc(sizeof(char) * my_strlen(nb1));
    nb1bis[0] = '-';
    for (int i = 1; nb1[i - 1] != '\0'; ++i)
        nb1bis[i] = nb1[i - 1];
    my_putchar('-');
    return (nb1bis);
}