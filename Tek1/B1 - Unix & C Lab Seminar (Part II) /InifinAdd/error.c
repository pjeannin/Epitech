/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error
*/

int isnum (char );

int error(int ac, char **av)
{
    int num = 0;

    if (ac != 3)
        return (1);
    for (int i = 1; i < ac; ++i) {
        if (av[i][0] != '-' && (av[i][0] <= 47 || av[i][0] >= 58))
            return (1);
        for (int j = 1; av[i][j] != '\0'; ++j)
            num += isnum(av[i][j]);
        if (num < 0)
            return (1);
    }
    return (0);
}