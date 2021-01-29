/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** infinadd
*/
#include<stdlib.h>

int error(int, char **);
void add(char *, char *);
void sub(char *, char *);
void rem_neg(char *, char *);
void my_putchar(char);


int main(int ac, char **av)
{
    int i;
    int err = 0;

    err = error (ac, av);
    if (err != 0)
        return (0);
    if (av[1][0] != '-' && av[2][0] != '-')
        add(av[1], av[2]);
    else if (av[1][0] == '-' && av[2][0] == '-') {
        rem_neg(av[1], av[2]);
        my_putchar('-');
        add(av[1], av[2]);
    }
    else {
        if (av[1][0] == '-' && av[2][0] != '-')
            sub(av[2], av[1]);
        else if (av[2][0] == '-' && av[1][0] != '-')
            sub(av[1], av[2]);
    }
    return (0);
}