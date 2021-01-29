/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** utils
*/

int read_int(int fd)
{
    int number = 0;
    unsigned char c;

    for (int i = 0; i < 4; ++i) {
        read(fd, &c, 1);
        number *= 256;
        number += c;
    }
    return (number);
}