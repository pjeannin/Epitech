/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** is_printable
*/

int is_printable(char c)
{
    if (c >= 32 && c <= 126)
        return (1);

    return (0);
}