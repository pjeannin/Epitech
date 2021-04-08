/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** objdump_s
*/

#include "../includes/objdump.h"

void objdump_s(Elf64_Ehdr *elf, void *buf)
{
    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elf->e_shoff);
    char *str_tab = (char *)(buf + shdr[elf->e_shstrndx].sh_offset);
    print_sections(shdr,str_tab, elf->e_shnum, buf);
}