/*
** EPITECH PROJECT, 2019
** comp.c
** File description:
** inf add
*/

int my_strlen(char *);
int my_strcmp(char *, char *);

int comp(char *nb1, char *nb2)
{
    char cpy[my_strlen(nb2)];

    for (int i = 0; nb2[i]; ++i)
        cpy[i] = nb2[i + 1];
    if (my_strlen(nb1) < my_strlen(cpy))
        return (1);
    else if (my_strlen(nb1) > my_strlen(cpy))
        return (-1);
    return (my_strcmp(cpy, nb1));
    
}