/*
** EPITECH PROJECT, 2020
** bootstrap_core_war
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
# define DIR_SIZE                4

typedef char    args_type_t;

struct op_s
{
    char         *mnemonique;
    char         nbr_args;
    args_type_t  type[3];
    char         code;
    int          nbr_cycles;
    char         *comment;
};

struct header_s
{
    int  magic;
# define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
};

typedef struct op_s     op_t;

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

int str_len(char *str)
{
    int len = 0;

    for (; str[len]; ++len);
    return (len);
}

char *rev_str(char *str)
{
    int j = str_len(str) - 1;
    char tmp;

    for (int i = 0; i < j; ++i) {
        tmp = str[i];
        str[i] = str[j];
        str[j--] = tmp;
    }
    return (str);
}

int strcomp(char *str1, char *str2)
{
    if (str_len(str1) != str_len(str2))
        return (0);
    for (int i = 0; str1[i] && str2[i]; ++i)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int strncomp(char *str1, char *str2, int n)
{
    if (str_len(str1) < n ||  str_len(str2) < n)
        return (0);
    for (int i = 0; i < n; ++i)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

char *convert_binary(int nb)
{
    char *bin_num = malloc(sizeof(char) * 9);
    int i = 0;

    for (; nb; ++i) {
        bin_num[i] = (nb % 2) + 48;
        nb /= 2;
    }
    for (; i < 8; ++i)
        bin_num[i] = '0';
    bin_num[i] = '\0';
    bin_num = rev_str(bin_num);
    bin_num[i] = '\0';
    return (bin_num);
}

int read_indi(int fd)
{
    int number = 0;
    unsigned char c;

    for (int i = 0; i < 2; ++i) {
        read(fd, &c, 1);
        number *= 256;
        number += c;
    }
    return (number);
}

int read_dir(int fd)
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

int read_reg(int fd)
{
    int number = 0;
    char c;

    read(fd, &c, 1);
    number = c;
    return (number);
}

long read_long(int fd)
{
    long number = 0;
    unsigned char c;

    for (int i = 0; i < 8; ++i) {
        read(fd, &c, 1);
        number *= 256;
        number += c;
    }
    return (number);
}

long read_header(int fd)
{
    int magic;
    long prog_size;
    char *prog_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
    char *comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);

    magic = read_int(fd);
    printf("magic = (%x)\n", magic);
    read(fd, prog_name, PROG_NAME_LENGTH);
    printf("program name = (%s)\n", prog_name);
    prog_size = read_long(fd);
    printf("porgram size (%ld)\n", prog_size);
    read(fd, comment, COMMENT_LENGTH);
    printf("comment = (%s)\n", comment);

    return (prog_size);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int number;
    long prog_size = read_header(fd);
    long read_bytes = 0;
    char *str = malloc(sizeof(char));
    unsigned char c;

    number = read_int(fd);
    printf("idk ceukeucé = (%d)\n", number);
    for (int j = 0; read_bytes < prog_size; ++j) {
        read_bytes += read(fd, &c, 1);
        printf("fonction %d = (%x)\n", j, c);
        if (c == 0x01) {
            number = read_int(fd);
            read_bytes += 4;
            printf("player number = (%d)\n", number);
        } else if (c == 0x09) {
            number = read_indi(fd);
            read_bytes += 2;
            printf("zjmp index = (%x)\n", number);
        } else if (c == 0x0c) {
            number = read_indi(fd);
            read_bytes += 2;
            printf("fork index = (%x)\n", number);
        } else if (c == 0x0f) {
            number = read_indi(fd);
            read_bytes += 2;
            printf("lfork index = (%x)\n", number);
        } else if (c == 0x0b) {
            read_bytes += read(fd, &c, sizeof(unsigned char));
            printf("args = (%s)\n", (str = convert_binary((int)c)));
            for (int i = 0; i < 3; ++i) {
                if (strncomp("10", &str[i * 2], 2)) {
                    number = read_indi(fd);
                    read_bytes += 2;
                    printf("arg %d est un %s", i + 1, "Dir");
                } else if (strncomp("01", &str[i * 2], 2)) {
                    read_bytes += 1;
                    number = read_reg(fd);
                    printf("arg %d est un %s", i + 1, "reg");
                } else if (strncomp("11", &str[i * 2], 2)) {
                    read_bytes += 2;
                    number = read_indi(fd);
                    printf("arg %d est un %s", i + 1, "indir");
                } else
                    break;
                printf(" = (%x)\n", number);
            }
        } else {
            read_bytes += read(fd, &c, sizeof(unsigned char));
            printf("args = (%s)\n", (str = convert_binary((int)c)));
            for (int i = 0; i < 3; ++i) {
                if (strncomp("10", &str[i * 2], 2)) {
                    number = read_dir(fd);
                    read_bytes += 4;
                    printf("arg %d est un %s", i + 1, "Dir");
                } else if (strncomp("01", &str[i * 2], 2)) {
                    read_bytes += 1;
                    number = read_reg(fd);
                    printf("arg %d est un %s", i + 1, "reg");
                } else if (strncomp("11", &str[i * 2], 2)) {
                    read_bytes += 2;
                    number = read_indi(fd);
                    printf("arg %d est un %s", i + 1, "indir");
                } else
                    break;
                printf(" = (%x)\n", number);
            }
        }
    }
    close(fd);
    return (0);
}