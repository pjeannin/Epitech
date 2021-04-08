/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-nmobjdump-pierre.jeannin
** File description:
** run_nm
*/

#include "../includes/nm.h"

void loop_test(void *buf, Elf64_Shdr *shdr, int i)
{
    int symnum = -1;
    Elf64_Sym* symtab;
    char *sh_strtab;

    if (shdr[i].sh_type == SHT_SYMTAB) {
            symtab = (Elf64_Sym *)(buf + shdr[i].sh_offset);
            symnum = shdr[i].sh_size/shdr[i].sh_entsize;
            sh_strtab = (char *)(buf + shdr[shdr[i].sh_link].sh_offset);
            for (int j = 0; j < symnum; ++j)
                if (strcmp("", sh_strtab + symtab[j].st_name) != 0)
                    printf("                   %s\n", sh_strtab
                    + symtab[j].st_name);
        }
}

int run_nm(char *filepath)
{
    void *buf;
    Elf64_Ehdr *elf = get_struct(filepath, &buf);
    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elf->e_shoff);

    if (elf == (Elf64_Ehdr *)-1)
        return (-1);
    else if (check_magic(elf->e_ident) == -1)
        return (-2);
    for (int i = 0; i < elf->e_shnum; ++i)
        loop_test(buf, shdr, i);

    return (0);
}