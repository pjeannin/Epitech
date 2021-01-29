/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays strings
*/

#include "../../include/my.h"
#include <unistd.h>

int my_putstr(int fd, char const *str)
{
    if (str)
        write(fd, str, my_strlen(str));
    else
        write(fd, "(NULL)\n", 7);
    return (0);
}

int my_putnstr(int fd, char const *str, int n)
{
    write(fd, str, n);
    return (0);
}

int my_puttwostr(int fd, char const *str, char const *str2)
{
    write(fd, str, my_strlen(str));
    write(fd, str2, my_strlen(str2));
    return (0);
}

int my_put2str(int fd, char **arr)
{
    for (int i = 0; arr && arr[i]; ++i) {
        my_putstr(fd, arr[i]);
        write (fd, "\n", 1);
    }
    return (0);
}
