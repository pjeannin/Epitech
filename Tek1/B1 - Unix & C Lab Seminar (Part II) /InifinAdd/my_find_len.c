/*
** EPITECH PROJECT, 2019
** my_find_len.c
** File description:
** my_find_len
*/
int my_strlen(char *);

int find_len(char *nb1, char *nb2)
{
    int res;

    if (my_strlen(nb1) > my_strlen(nb2))
        res = my_strlen(nb1);
    else
        res = my_strlen(nb2);
    return (res);
}
