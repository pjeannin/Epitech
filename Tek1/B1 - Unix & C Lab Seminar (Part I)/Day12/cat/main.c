/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** cat
*/
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>

void my_putchar(char);
void my_putstr(char *);
void my_put_nbr(int);

void error_display(char *file, int error, int *psize)
{
    if (error != 0) {
        write(2, "cat: ", 6);
        write(2, file, (my_strlen(file) + 1));
        write(2, ": ", 3);
        if (error == EACCES)
            write(2, "Permission denied\n", 18);
        else if (error == ENOENT)
            write(2, "No such file or directory\n", 26);
        *psize = 84;
    }
}
int main (int ac, char **av)
{
    int fd;
    char buffer[11];
    int size;
    int *psize = &size;

    for (int j = 1; j < ac; ++j) {
        size = 1;
        errno = 0;
        fd = open(av[j], O_RDONLY);
        error_display(av[j], errno, psize);
        while (size != 0 && size != 84 && size != -1) {
            size = read(fd, buffer, 10);
            my_putstr(buffer);
            for (int i = 0; buffer[i] != '\0'; ++i)
                buffer[i] = 0;
        }
        if (size == -1) {
            write(2, "cat: ", 6);
            write(2, av[j], (my_strlen(av[j]) + 1));
            write(2, ": ", 3);
            write(2, "Is a directory\n", 15);
        }
        close(fd);
    }
}