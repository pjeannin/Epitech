/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_section
*/

#include "../includes/objdump.h"

void print_sections(Elf64_Shdr *shdr, char *str_tab, int shNum, uint8_t *data)
{
    for (int i = 0; i < shNum; i++)
        if (str_tab[shdr[i].sh_name] != '\0'
        && strcmp(&str_tab[shdr[i].sh_name], ".bss") != 0
        && strcmp(&str_tab[shdr[i].sh_name], ".shstrtab") != 0
        && strcmp(&str_tab[shdr[i].sh_name], ".symtab") != 0
        && strcmp(&str_tab[shdr[i].sh_name], ".strtab") != 0
        && shdr[i].sh_size != 0)
            print_section(shdr, str_tab, data, i);
}