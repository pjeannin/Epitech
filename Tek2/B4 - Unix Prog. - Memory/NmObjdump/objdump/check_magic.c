/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_magic
*/

int check_magic(unsigned char *magic)
{
    if (magic[0] != 0x7f || magic[1] != 'E'
    || magic[2] != 'L' || magic[3] != 'F')
        return (-1);

    return (0);
}