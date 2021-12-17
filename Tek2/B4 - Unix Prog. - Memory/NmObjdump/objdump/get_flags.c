/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_flags
*/

#include "../includes/objdump.h"

unsigned int end_flags(Elf64_Ehdr *elf)
{
    if (elf->e_type == ET_REL)
        return (HAS_RELOC);

    return (0);
}

unsigned int get_flags(Elf64_Ehdr *elf)
{
    unsigned int flags = BFD_NO_FLAGS;
    Elf64_Shdr *elfhead = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);

    if (elf->e_type == ET_EXEC)
        flags += EXEC_P + D_PAGED;
    else if (elf->e_type == ET_DYN)
        flags += DYNAMIC + D_PAGED;
    else
        flags += end_flags(elf);
    for (int i = 0; i < elf->e_shnum; ++i)
        if (elfhead[i].sh_type == SHT_SYMTAB)
            return (flags + HAS_SYMS);

    return (flags);
}