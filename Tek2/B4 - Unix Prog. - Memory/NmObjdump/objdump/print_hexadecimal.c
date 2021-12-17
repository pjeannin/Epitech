/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_hexadecimal
*/

#include "../includes/objdump.h"

void print_hexadecimal(Elf64_Shdr shdr, char *buffer, unsigned int index)
{
    char c;

    while (index < shdr.sh_size) {
        c = (buffer + shdr.sh_offset)[index];
        printf("%02x", (unsigned char)c);
        ++index;
        if (index % 16 == 0) {
            printf("  ");
            break;
        }
        if (index % 4 == 0)
            printf(" ");
    }
    if (index >= shdr.sh_size && index % 16 != 0)
        print_space(index, 0);
}