/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** revstr
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int swap;

    while (str[a] != '\0')
        a++;
    a--;
    while (a >= b) {
        swap = str[a];
        str[a] = str[b];
        str[b] = swap;
        b++;
        a--;
    }
    return (str);
}
