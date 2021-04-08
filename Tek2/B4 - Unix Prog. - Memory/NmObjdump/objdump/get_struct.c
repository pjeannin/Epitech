/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_struct
*/

#include "../includes/objdump.h"

Elf64_Ehdr *get_struct(char *filepath, void **buf)
{
    struct stat bufstat;
    int fd;

    if ((fd = open(filepath, O_RDONLY)) == -1)
        return ((Elf64_Ehdr *)-1);
    if (fstat(fd, &bufstat) == -1) {
        close(fd);
        return ((Elf64_Ehdr *)-1);
    }
    (*buf) = mmap(NULL, bufstat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (*buf == (void *)-1) {
        perror("mmap");
        close(fd);
        return ((Elf64_Ehdr *)-1);
    }
    close(fd);

    return ((Elf64_Ehdr *)*buf);
}