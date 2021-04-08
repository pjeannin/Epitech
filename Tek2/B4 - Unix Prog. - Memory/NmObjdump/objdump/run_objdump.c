/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-nmobjdump-pierre.jeannin
** File description:
** run_objdump
*/

#include "../includes/objdump.h"

int run_objdump(char *filepath)
{
    void *buf;
    Elf64_Ehdr *elf = get_struct(filepath, &buf);

    if (elf == (Elf64_Ehdr *)-1)
        return (-1);
    else if (check_magic(elf->e_ident) == -1)
        return (-2);

    objdump_f(elf, filepath);
    objdump_s(elf, buf);

    return (0);
}