/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include<unistd.h>

int rush3(char *);

int main(void)
{
    int BUFF_SIZE = 500000;
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    int error;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0)
        offset += len;
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    error = rush3(buff);
    if (error == 84)
        return(84);
    return (0);
}
