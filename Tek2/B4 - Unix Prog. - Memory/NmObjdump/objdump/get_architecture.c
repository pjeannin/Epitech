/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_architechture
*/

#include "../includes/objdump.h"

char *get_architechture(int e_machine)
{
    if (e_machine == EM_386)
        return ("i386");
    else if (e_machine == EM_X86_64)
        return ("i386:x86-64");

    return ("Unknown");
}