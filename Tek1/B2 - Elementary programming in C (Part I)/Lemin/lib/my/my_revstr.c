/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** revstr
*/

char *my_revstr(char *str)
{
    int a;
    int b;
    int swap;

    b = 0;
    while (str[a] != '\0') {
        a++;
    }
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
