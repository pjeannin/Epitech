/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** objdump_f
*/

#include "../includes/objdump.h"

void objdump_f(Elf64_Ehdr *elf, char *filepath)
{
    printf("\n%s:     file format %s\n", filepath, "elf64-x86-64");
    printf("architecture: %s, flags 0x%08x:\n",
    get_architechture(elf->e_machine), get_flags(elf));
    print_flags(get_flags(elf));
    printf("start address 0x%016lx\n\n", elf->e_entry);
}