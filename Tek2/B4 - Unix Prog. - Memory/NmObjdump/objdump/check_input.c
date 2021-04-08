/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-nmobjdump-pierre.jeannin
** File description:
** check_input
*/

#include "../includes/objdump.h"

int message(char *message, char *filename)
{
    dprintf(2, message, filename);

    return (-1);
}

int check_input(int argc, char **argv)
{
    int i = 1;
    int return_value = 0;
    int tmp = 0;

    if (argc == 1)
        if (run_objdump("a.out") == -1)
            return (message("my_objdump: '%s': No such file\n", "a.out"));
    while (i < argc) {
        tmp = run_objdump(argv[i]);
        if (tmp == -1)
            return_value = message("my_objdump: '%s': No such file\n", argv[i]);
        else if (tmp == -2)
            return_value =
            message("my_objdump: %s: file format not recognized\n",
            argv[i]);
        ++i;
    }

    return (return_value);
}