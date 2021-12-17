/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_section
*/

#include "../includes/objdump.h"

void print_section(Elf64_Shdr *shdr, char *str_tab, uint8_t *data, int i)
{
    unsigned int index = 0;
    unsigned int tmp = shdr[i].sh_addr;
    char c;

    printf("Contents of section %s:\n", &str_tab[shdr[i].sh_name]);
    while (index < shdr[i].sh_size) {
        if (index % 16 == 0) {
            printf(" %04x ", tmp);
            tmp += 16;
            print_hexadecimal(shdr[i], data, index);
        }
        c = (data + shdr[i].sh_offset)[index];
        printf("%c", is_printable(c) ? c : '.');
        ++index;
        if (index % 16 == 0)
            printf("\n");
    }
    if (index >= shdr[i].sh_size && index % 16 != 0)
        print_space(index, 1);
}