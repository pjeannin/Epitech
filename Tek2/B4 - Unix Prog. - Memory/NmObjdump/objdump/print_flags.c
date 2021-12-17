/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** print_flags
*/

#include "../includes/objdump.h"

void print_flags(unsigned int flags)
{
    uint16_t flags_value[8] = {BFD_NO_FLAGS, HAS_RELOC, EXEC_P, HAS_DEBUG,
    HAS_SYMS, HAS_LOCALS, DYNAMIC, D_PAGED};
    char flags_str[8][12] = {"BFD_NO_FLAGS", "HAS_RELOC", "EXEC_P", "HAS_DEBUG",
    "HAS_SYMS", "HAS_LOCALS", "DYNAMIC", "D_PAGED"};
    int first = 0;

    for (int i = 0; i < 8; i++) {
        if (flags & flags_value[i]) {
            printf("%s%s", first ? ", " : "", flags_str[i]);
            first++;
            flags -= flags_value[i];
        }
    }
    printf("\n");
}